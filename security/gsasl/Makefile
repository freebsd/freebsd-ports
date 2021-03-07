# Created by: ijliao
# $FreeBSD$

PORTNAME=	gsasl
PORTVERSION=	1.10.0
CATEGORIES=	security
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GNU SASL command-line utility

LICENSE=	LGPL21

LIB_DEPENDS=	libgsasl.so:security/libgsasl

USES=		charsetfix libtool localbase pathfix pkgconfig readline

CONFIGURE_ARGS=	--disable-rpath \
		--without-gssapi-impl
GNU_CONFIGURE=	yes

INFO=		gsasl

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
