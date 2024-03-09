PORTNAME=	gsasl
PORTVERSION=	2.2.1
CATEGORIES=	security
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GNU SASL command-line utility
WWW=		https://www.gnu.org/software/gsasl/

LICENSE=	LGPL21

LIB_DEPENDS=	libgsasl.so:security/libgsasl

USES=		charsetfix libtool localbase pathfix pkgconfig readline

CONFIGURE_ARGS=	--disable-rpath \
		--without-gssapi-impl
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INFO=		gsasl

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

DOCS_USES=		makeinfo
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-build-DOCS-on:
	cd ${WRKSRC}/doc && ${MAKE_CMD} gsasl.html

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/gsasl.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
