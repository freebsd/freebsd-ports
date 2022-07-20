PORTNAME=	pam_p11
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/OpenSC/pam_p11/releases/download/pam_p11-${PORTVERSION}/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	PAM module using crypto tokens for auth

LICENSE=	LGPL21

LIB_DEPENDS=	libp11.so:security/libp11

USES=		libtool pkgconfig ssl

OPTIONS_DEFINE=	DOCS NLS

GNU_CONFIGURE=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
NLS_PLIST_FILES=share/locale/de/LC_MESSAGES/pam_p11.mo \
		share/locale/it/LC_MESSAGES/pam_p11.mo

CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"

INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/security/pam_p11.so

PORTDOCS=	*

post-install:
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
