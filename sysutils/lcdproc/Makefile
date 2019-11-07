# Created by: pat
# $FreeBSD$

PORTNAME=	lcdproc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.9
CATEGORIES=	sysutils

MAINTAINER=	daniel@shafer.cc
COMMENT=	Client/server suite for LCD devices

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	i386 amd64

USES=		autoreconf pkgconfig
GNU_CONFIGURE=	yes
USE_RC_SUBR=	LCDd lcdproc lcdexec
USE_GITHUB=	yes

CONFIGURE_ARGS=	--enable-drivers="${LCDPROC_DRIVERS}" \
		--disable-dependency-tracking \
		--disable-libusb-1-0 \
		--disable-doxygen

SUB_FILES=	pkg-message

# Options
OPTIONS_DEFINE=	USB FTDI HID FREETYPE PNG SERDISP X11
USB_DESC=	USB support
FTDI_DESC=	Build drivers using libftdi (requires USB)
HID_DESC=	Build drivers using libhid (requires USB)
SERDISP_DESC=	Build drivers using serdisplib

OPTIONS_DEFAULT=USB FREETYPE
NO_OPTIONS_SORT=yes

FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_ENABLE=	libpng

SERDISP_LIB_DEPENDS=	libserdisp.so:devel/serdisplib
SERDISP_CFLAGS=		-I${LOCALBASE}/include
SERDISP_LDFLAGS=	-L${LOCALBASE}/lib
SERDISP_CPPFLAGS=	-I${LOCALBASE}/include

X11_USES=		xorg
X11_USE=		xorg=x11
X11_CONFIGURE_ENABLE=	libX11

LCDPROC_DRIVERS=bayrad \
		CFontz \
		CFontzPacket \
		CwLnx \
		curses \
		ea65 \
		EyeboxOne \
		glcd \
		glk \
		hd44780 \
		icp_a106 \
		lb216 \
		lcdm001 \
		lcterm \
		MD8800 \
		ms6931 \
		mtc_s16209x \
		MtxOrb \
		NoritakeVFD \
		pyramid \
		rawserial \
		SureElec \
		sdeclcd \
		sed1330 \
		sed1520 \
		serialPOS \
		serialVFD \
		sli \
		stv5730 \
		t6963 \
		text \
		tyan \
		vlsys_m428

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUSB}
CONFIGURE_ARGS+=	--enable-libusb
PLIST_SUB+=		USB=""
LCDPROC_DRIVERS+=IOWarrior \
		picolcd \
		shuttleVFD

. if ${PORT_OPTIONS:MFTDI}
LIB_DEPENDS+=		libftdi1.so:devel/libftdi1
PLIST_SUB+=		FTDI=""
LCDPROC_DRIVERS+=i2500vfd \
		lis \
		ula200
. else
CONFIGURE_ARGS+=	--disable-libftdi
PLIST_SUB+=		FTDI="@comment "
. endif

. if ${PORT_OPTIONS:MHID}
LIB_DEPENDS+=		libhid.so:devel/libhid
PLIST_SUB+=		HID=""
LCDPROC_DRIVERS+=mdm166a
. else
CONFIGURE_ARGS+=	--disable-libhid
PLIST_SUB+=		HID="@comment "
. endif

.else
CONFIGURE_ARGS+=	--disable-libusb --disable-libftdi --disable-libhid
PLIST_SUB+=		USB="@comment " FTDI="@comment " HID="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's!server/drivers!${PREFIX}/lib/lcdproc!' ${WRKSRC}/LCDd.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/LCDd.conf ${STAGEDIR}${PREFIX}/etc/LCDd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/clients/lcdproc/lcdproc.conf ${STAGEDIR}${PREFIX}/etc/lcdproc.conf.sample
	${INSTALL_DATA} ${WRKSRC}/clients/lcdexec/lcdexec.conf ${STAGEDIR}${PREFIX}/etc/lcdexec.conf.sample

.include <bsd.port.mk>
