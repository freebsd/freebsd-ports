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

MAINTAINER=	pauls@utdallas.edu
COMMENT?=	An output system for Snort

RUN_DEPENDS+=	${LOCALBASE}/bin/snort:${PORTSDIR}/security/snort

OPTIONS=	MYSQL "Enable MySQL support" off \
		POSTGRESQL "Enable PostgreSQL support" off

USE_AUTOTOOLS=	autoheader:259 aclocal:19
USE_RC_SUBR=	barnyard.sh
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
SLAVEDIRS=	security/barnyard-sguil6
SUB_FILES=	pkg-message

DOCS=		AUTHORS COPYING LICENSE.QPL README
PORTDOCS=	BUGS ChangeLog FAQ INSTALL NEWS USAGE

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--enable-mysql
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--enable-postgres
.endif

post-install:

.for f in barnyard.conf
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${PREFIX}/etc/${f}-sample
	[ -f ${PREFIX}/etc/${f} ] || \
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${PREFIX}/etc/${f}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
