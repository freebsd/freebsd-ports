# New ports collection makefile for:	barnyard
# Date created:				1 Feb 2005
# Whom:					pauls
#
# $FreeBSD$
#

PORTNAME=	barnyard
PORTVERSION=	0.2.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	barnyard
#DISTNAME=	barnyard

MAINTAINER=	pauls@utdallas.edu
COMMENT=	An output system for Snort

RUN_DEPENDS=	${LOCALBASE}/bin/snort:${PORTSDIR}/security/snort

OPTIONS=	MYSQL "Enable MySQL support" off \
		POSTGRESQL "Enable PostgreSQL support" off

USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_REINPLACE=	yes
USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DOCS=		AUTHORS COPYING LICENSE.QPL README docs/BUGS docs/ChangeLog \
		docs/FAQ docs/INSTALL docs/NEWS docs/USAGE

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--enable-mysql
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--enable-postgres
.endif

post-patch:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/barnyard.sh > ${WRKDIR}/barnyard.sh

post-install:
	${INSTALL_SCRIPT} -m 751 ${WRKDIR}/barnyard.sh ${PREFIX}/etc/rc.d/barnyard.sh
.for f in barnyard.conf
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${PREFIX}/etc/${f}-sample
	[ -f ${PREFIX}/etc/${f} ] || \
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${PREFIX}/etc/${f}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
