# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	pam_mysql
PORTVERSION=	0.7.r1
PORTREVISION=	2
CATEGORIES=	security databases
MASTER_SITES=	SF/pam-mysql/pam-mysql/0.7RC1
DISTNAME=	${PORTNAME}-0.7RC1${DISTVERSIONSUFFIX}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	A pam module for authenticating with MySQL

USE_MYSQL=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal14 autoconf libtool
ACLOCAL_ARGS=	-I ${PREFIX}/share/aclocal
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE} --with-pam-mods-dir=${PREFIX}/lib --with-pam=/usr

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_FILES=	lib/pam_mysql.la lib/pam_mysql.so lib/pam_mysql.a

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
