# Created by: Bruce M Simpson
# $FreeBSD$

PORTNAME=	opensc
DISTVERSION=	0.20.0
CATEGORIES=	security devel

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Libraries and utilities to access smart cards

LICENSE=	LGPL21

USES=		autoreconf compiler:c11 gmake libtool pkgconfig ssl

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=PCSC OPENCT CTAPI
OPTIONS_DEFINE=	SM NOTIFY DOCS MANPAGES
OPTIONS_DEFAULT=PCSC SM NOTIFY MANPAGES
OPTIONS_SUB=	yes

PCSC_DESC=	Use PC/SC backend
OPENCT_DESC=	Use OpenCT backend
CTAPI_DESC=	Use CT-API backend
SM_DESC=	Enable secure messaging support
NOTIFY_DESC=	Enable notification support

USE_GITHUB=	yes
GH_ACCOUNT=	OpenSC
GH_PROJECT=	${GH_ACCOUNT}

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ENV=	\
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"
CONFIGURE_ARGS=	--with-completiondir=${PREFIX}/etc/bash_completion.d

PORTDOCS=	*

MANPAGES_CONFIGURE_ENABLE=	man

OPENCT_LIB_DEPENDS=	libopenct.so:security/openct
OPENCT_CONFIGURE_ENABLE=	openct

PCSC_LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
PCSC_CONFIGURE_ENABLE=	pcsc

CTAPI_CONFIGURE_ENABLE=		ctapi

SM_CONFIGURE_ENABLE=		sm

NOTIFY_USES=			gnome
NOTIFY_USE=			GNOME=glib20
NOTIFY_CONFIGURE_ENABLE=	notify

DOCS_CONFIGURE_ENABLE=		doc

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
