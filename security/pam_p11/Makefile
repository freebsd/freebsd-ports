# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pam_p11
PORTVERSION=	0.2.0
CATEGORIES=	security
MASTER_SITES=	https://github.com/OpenSC/pam_p11/releases/download/pam_p11-${PORTVERSION}/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	PAM module using crypto tokens for auth

LICENSE=	LGPL21

LIB_DEPENDS=	libp11.so:security/libp11

USES=		libtool pkgconfig ssl

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"

PLIST_FILES=	lib/security/pam_p11.so

PORTDOCS=	*

post-install:
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
