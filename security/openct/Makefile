# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	openct
PORTVERSION=	0.6.20
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/opensc/${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Middleware framework for smart card terminals

LICENSE=	LGPL21

LIB_DEPENDS=	libltdl.so:devel/libltdl

OPTIONS_DEFINE=	PCSC DOCS
PCSC_DESC=	Enable PC/SC support

GNU_CONFIGURE=	yes
USES=		gmake libtool pkgconfig
USE_LDCONFIG=	yes
USE_RC_SUBR=	openct
SUB_FILES=	etoken.conf

CONFIGURE_ENV=	LTLIB_CFLAGS="-I${LOCALBASE}/include" \
		LTLIB_LIBS="-L${LOCALBASE}/lib -lltdl" \
		LIBUSB_CFLAGS="-I/usr/include" \
		LIBUSB_LIBS="-lusb"

CONFIGURE_ARGS=	--localstatedir=/var --enable-usb

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPCSC}
LIB_DEPENDS+=	libpcsclite.so:devel/pcsc-lite
CONFIGURE_ARGS+=--enable-pcsc
PLIST_SUB+=	PCSC=""
.else
PLIST_SUB+=	PCSC="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--enable-doc
.endif

post-patch:
	@${REINPLACE_CMD} 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} 's|install-data-am: install-dist_apidocDATA install-dist_docDATA|install-data-am: install-dist_docDATA|' \
		${WRKSRC}/doc/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKDIR}/etoken.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
