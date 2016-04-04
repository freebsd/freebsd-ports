# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pam_p11
PORTVERSION=	0.1.5
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF/opensc/${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	PAM module using crypto tokens for auth

LICENSE=	LGPL21

LIB_DEPENDS=	libp11.so:security/libp11

OPTIONS_DEFINE=	DOCS

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USES=		libtool pkgconfig

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lssl"

PORTDOCS=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/wiki
	@(cd ${WRKSRC} && ${CP} NEWS ${STAGEDIR}${DOCSDIR})
	@(cd ${WRKSRC}/doc && ${CP} README ${STAGEDIR}${DOCSDIR})
	@(cd ${WRKSRC}/doc && ${CP} *.css *.html ${STAGEDIR}${DOCSDIR}/wiki)

.include <bsd.port.mk>
