# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	openct
PORTVERSION=	0.6.20
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	opensc/${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Middleware framework for smart card terminals

OPTIONS_DEFINE=	PCSC DOCS
PCSC_DESC=	Enable PC/SC support

USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
USE_RC_SUBR=	openct
SUB_FILES=	etoken.conf

CONFIGURE_ENV=	LTLIB_CFLAGS="-I${LOCALBASE}/include" \
		LTLIB_LIBS="-L${LOCALBASE}/lib -lltdl"

CONFIGURE_ARGS=	--localstatedir=/var

MAN1=		openct-tool.1

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800069
CONFIGURE_ENV+=	LIBUSB_CFLAGS="-I/usr/include" \
		LIBUSB_LIBS="-lusb"

CONFIGURE_ARGS+=--enable-usb
.endif

.if ${PORT_OPTIONS:MPCSC}
LIB_DEPENDS+=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite
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
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} 's|install-data-am: install-dist_apidocDATA install-dist_docDATA|install-data-am: install-dist_docDATA|' \
		${WRKSRC}/doc/Makefile.in
.else
	@${REINPLACE_CMD} 's|install-data-am: install-dist_docDATA|install-data-am:|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} 's|install-data-am: install-dist_apidocDATA install-dist_docDATA|install-data-am:|' \
		${WRKSRC}/doc/Makefile.in
.endif

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKDIR}/etoken.conf ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
