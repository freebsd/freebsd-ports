# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	pam_mysql
PORTVERSION=	0.7.r1
PORTREVISION=	4
CATEGORIES=	security databases
MASTER_SITES=	SF/pam-mysql/pam-mysql/0.7RC1
DISTNAME=	${PORTNAME}-0.7RC1${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pam module for authenticating with MySQL

USES=		libtool:keepla
USE_MYSQL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE} --with-pam-mods-dir=${PREFIX}/lib --with-pam=/usr

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_FILES=	lib/pam_mysql.so lib/pam_mysql.la

PORTDOCS=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog \
		${WRKSRC}/NEWS \
		${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
