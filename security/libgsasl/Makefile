# Created by: ijliao
# $FreeBSD$

PORTNAME=	gsasl
PORTVERSION=	1.8.1
CATEGORIES=	security
MASTER_SITES=	GNU
PKGNAMEPREFIX=	lib

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GNU SASL library

LICENSE=	LGPL21

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libidn.so:dns/libidn \
		libntlm.so:security/libntlm

USES=		charsetfix libtool pathfix pkgconfig ssl

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_DEFAULT=GSSAPI_BASE
OPTIONS_SINGLE=	GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_SUB=	yes

GSSAPI_BASE_CONFIGURE_ON=	--with-gssapi-impl=heimdal ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_BASE_USES=	gssapi
GSSAPI_HEIMDAL_CONFIGURE_WITH=	--with-gssapi-impl=heimdal ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_CONFIGURE_ON=--with-gssapi-impl=mit ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_NONE_CONFIGURE_ON=	--disable-gssapi
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-patch:
	@${REINPLACE_CMD} -e '/^en@/d' ${WRKSRC}/lib/po/LINGUAS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/reference
	${INSTALL_DATA} ${WRKSRC}/doc/reference/html/* ${STAGEDIR}${DOCSDIR}/reference

.include <bsd.port.mk>
