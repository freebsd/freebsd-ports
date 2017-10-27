# Created by: Bruce M Simpson
# $FreeBSD$

PORTNAME=	opensc
PORTVERSION=	0.17.0
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	https://github.com/OpenSC/OpenSC/releases/download/0.17.0/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Libraries and utilities to access smart cards

LICENSE=	LGPL21

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=PCSC OPENCT CTAPI
OPTIONS_DEFINE=	SM DOCS MANPAGES
OPTIONS_DEFAULT=PCSC SM MANPAGES
OPTIONS_SUB=	yes

PCSC_DESC=	Use PC/SC backend
OPENCT_DESC=	Use OpenCT backend
CTAPI_DESC=	Use CT-API backend
SM_DESC=	Enable secure messaging support

USES=		libtool pkgconfig gmake ssl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ENV=	\
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"

PORTDOCS=	*

MANPAGES_CONFIGURE_ARGS_OFF=--disable-man

OPENCT_LIB_DEPENDS=	libopenct.so:security/openct
OPENCT_CONFIGURE_ARGS=	--enable-openct

PCSC_LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
PCSC_CONFIGURE_ARGS_OFF=--disable-pcsc
CTAPI_CONFIGURE_ARGS=	--enable-ctapi
SM_CONFIGURE_ARGS_OFF=	--disable-sm
DOCS_CONFIGURE_ARGS+=	--enable-doc

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

.include <bsd.port.mk>
