# New ports collection makefile for:	barnyard2
# Date created:				28 Aug 2009
# Whom:					pauls
#
# $FreeBSD$
#

PORTNAME=	barnyard2
PORTVERSION=	1.6
CATEGORIES=	security
MASTER_SITES=	http://www.securixlive.com/download/barnyard2/

MAINTAINER=	pauls@utdallas.edu
COMMENT=	An output system for Snort that parses unified2 files

RUN_DEPENDS+=	${LOCALBASE}/bin/snort:${PORTSDIR}/security/snort

OPTIONS=	MYSQL "Enable MySQL support" on \
		POSTGRESQL "Enable PostgreSQL support" off

USE_RC_SUBR=	barnyard2.sh
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
SUB_FILES=	pkg-message

PORTDOCS=	INSTALL	README README.aruba README.database README.sguil

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql \
			--with-mysql-includes=${LOCALBASE}/include/mysql \
			--with-mysql-libraries=${LOCALBASE}/lib/mysql
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-postgresql
.endif

post-install:

.for f in barnyard2.conf
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${PREFIX}/etc/${f}-sample
	[ -f ${PREFIX}/etc/${f} ] || \
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${PREFIX}/etc/${f}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
#	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
