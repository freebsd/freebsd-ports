# Created by: Bruce M Simpson
# $FreeBSD$

PORTNAME=	opensc
PORTVERSION=	0.14.0
CATEGORIES=	security devel
MASTER_SITES=	SF/${PORTNAME}/OpenSC/${DISTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Libraries and utilities to access smart cards

LICENSE=	LGPL21

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=PCSC OPENCT CTAPI
OPTIONS_DEFINE=	SM DOCS
OPTIONS_DEFAULT=PCSC SM

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
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto" \
		XSLTPROC="${LOCALBASE}/bin/xsltproc"

CONFIGURE_ARGS=	--with-xsl-stylesheetsdir=${LOCALBASE}/share/xsl/docbook

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENCT}
LIB_DEPENDS+=	libopenct.so:${PORTSDIR}/security/openct
CONFIGURE_ARGS+=--enable-openct
.endif

.if ${PORT_OPTIONS:MPCSC}
LIB_DEPENDS+=	libpcsclite.so:${PORTSDIR}/devel/pcsc-lite
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
