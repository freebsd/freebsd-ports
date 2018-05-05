# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	pam_mysql
PORTVERSION=	0.7.r1
PORTREVISION=	5
CATEGORIES=	security databases
MASTER_SITES=	SF/pam-mysql/pam-mysql/0.7RC1
DISTNAME=	${PORTNAME}-0.7RC1${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pam module for authenticating with MySQL

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool:keepla
USE_MYSQL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE} \
		--with-pam-mods-dir=${PREFIX}/lib \
		--with-pam=/usr

SUB_FILES=	pkg-message

PORTDOCS=	*
PLIST_FILES=	lib/pam_mysql.so lib/pam_mysql.la

OPTIONS_DEFINE= SSL
SSL_DESC=	Build with OpenSSL support (non-crypt()ish MD5 hash)
SSL_CONFIGURE_WITH= openssl

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pam_mysql.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/NEWS \
		${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
