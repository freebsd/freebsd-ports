# Created by: Bruce M Simpson
# $FreeBSD$

PORTNAME=	opensc
PORTVERSION=	0.16.0
CATEGORIES=	security devel
MASTER_SITES=	SF/${PORTNAME}/OpenSC/${DISTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Libraries and utilities to access smart cards

LICENSE=	LGPL21

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=PCSC OPENCT CTAPI
OPTIONS_DEFINE=	SM DOCS MANPAGES
OPTIONS_DEFAULT=PCSC SM MANPAGES

PCSC_DESC=	Use PC/SC backend
OPENCT_DESC=	Use OpenCT backend
CTAPI_DESC=	Use CT-API backend
SM_DESC=	Enable secure messaging support

USES=		libtool pkgconfig gmake
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ENV=	\
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS} || ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	xsltproc:textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl
CONFIGURE_ENV+=	XSLTPROC="${LOCALBASE}/bin/xsltproc"
CONFIGURE_ARGS+=--with-xsl-stylesheetsdir=${LOCALBASE}/share/xsl/docbook
.else
CONFIGURE_ENV+=	XSLTPROC="${FALSE}"
CONFIGURE_ARGS+=--without-xsl-stylesheetsdir
.endif

.if ${PORT_OPTIONS:MMANPAGES}
PLIST_SUB+=	MANPAGES=""
.else
CONFIGURE_ARGS+=--disable-man
PLIST_SUB+=	MANPAGES="@comment "
.endif

.if ${PORT_OPTIONS:MOPENCT}
LIB_DEPENDS+=	libopenct.so:security/openct
CONFIGURE_ARGS+=--enable-openct
.endif

.if ${PORT_OPTIONS:MPCSC}
LIB_DEPENDS+=	libpcsclite.so:devel/pcsc-lite
.else
CONFIGURE_ARGS+=--disable-pcsc
.endif

.if ${PORT_OPTIONS:MCTAPI}
CONFIGURE_ARGS+=--enable-ctapi
.endif

.if ${PORT_OPTIONS:MSM}
PLIST_SUB+=	SM=""
.else
CONFIGURE_ARGS+=--disable-sm
PLIST_SUB+=	SM="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--enable-doc
.endif

.include <bsd.port.mk>
