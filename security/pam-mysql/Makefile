PORTNAME=	pam_mysql
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
CATEGORIES=	security databases

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	PAM module for authenticating with MySQL

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c11 libtool:keepla mysql pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	NigelCunningham
GH_PROJECT=	pam-MySQL
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-pam=/usr/lib --with-pam-mods-dir=${LOCALBASE}/lib
SUB_FILES=	pkg-message

PORTDOCS=	*
PLIST_FILES=	lib/pam_mysql.so lib/pam_mysql.la

OPTIONS_DEFINE=	DOCS SSL
OPTIONS_DEFAULT=	DOCS SSL

SSL_DESC=		Build with OpenSSL support (non-crypt()ish MD5 and SHA1 hash)
SSL_CONFIGURE_ENV=	openssl_CFLAGS="${OPENSSLINC}" \
			openssl_LIBS="${OPENSSLLIB}"
SSL_CONFIGURE_WITH=	openssl
SSL_USES=		ssl

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pam_mysql.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/NEWS \
		${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
