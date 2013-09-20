# Created by: pat
# $FreeBSD$

PORTNAME=	lcdproc
PORTVERSION=	0.5.6
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	bsdfan@nurfuerspam.de
COMMENT=	Client/server suite for LCD devices

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	i386 amd64

USE_AUTOTOOLS=	autoconf automake aclocal
GNU_CONFIGURE=	yes
USE_RC_SUBR=	LCDd lcdproc lcdexec
USES=		pkgconfig

CONFIGURE_ARGS=	--enable-drivers="${LCDPROC_DRIVERS}" \
		--disable-dependency-tracking \
		--disable-libusb-1-0 \
		--disable-doxygen

SUB_FILES=	pkg-message

MAN1=		lcdexec.1 lcdproc.1
MAN5=		lcdproc-config.5
MAN8=		LCDd.8

OPTIONS_DEFINE=	USB FTDI HID FREETYPE PNG SERDISP
USB_DESC=	USB support
FTDI_DESC=	Build drivers using libftdi (requires USB)
HID_DESC=	Build drivers using libhid (requires USB)
SERDISP_DESC=	Build drivers using serdisplib
OPTIONS_DEFAULT=USB FREETYPE
NO_OPTIONS_SORT=yes

# Empty args to aclocal required!
ACLOCAL_ARGS=

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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUSB}
CONFIGURE_ARGS+=	--with-libusb=/usr
PLIST_SUB+=		USB=""
LCDPROC_DRIVERS+=IOWarrior \
		picolcd \
		shuttleVFD

. if ${PORT_OPTIONS:MFTDI}
LIB_DEPENDS+=		ftdi:${PORTSDIR}/devel/libftdi
PLIST_SUB+=		FTDI=""
LCDPROC_DRIVERS+=i2500vfd \
		lis \
		ula200
. else
CONFIGURE_ARGS+=	--disable-libftdi
PLIST_SUB+=		FTDI="@comment "
. endif

. if ${PORT_OPTIONS:MHID}
LIB_DEPENDS+=		hid:${PORTSDIR}/devel/libhid
PLIST_SUB+=		HID=""
LCDPROC_DRIVERS+=mdm166a
. else
CONFIGURE_ARGS+=	--disable-libhid
PLIST_SUB+=		HID="@comment "
. endif

.else
CONFIGURE_ARGS+=	--without-libusb --disable-libftdi --disable-libhid
PLIST_SUB+=		USB="@comment " FTDI="@comment " HID="@comment "
.endif

.if ${PORT_OPTIONS:MFREETYPE}
LIB_DEPENDS+=		freetype:${PORTSDIR}/print/freetype2
.else
CONFIGURE_ARGS+=	--disable-freetype
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=		png15:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=	--disable-libpng
.endif

.if ${PORT_OPTIONS:MSERDISP}
LIB_DEPENDS+=		serdisp:${PORTSDIR}/devel/serdisplib
CFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CPPFLAGS+=		-I${LOCALBASE}/include
.endif

post-patch:
	@${REINPLACE_CMD} -e 's!server/drivers!${PREFIX}/lib/lcdproc!' ${WRKSRC}/LCDd.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/LCDd.conf ${PREFIX}/etc/LCDd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/clients/lcdproc/lcdproc.conf ${PREFIX}/etc/lcdproc.conf.sample
	${INSTALL_DATA} ${WRKSRC}/clients/lcdexec/lcdexec.conf ${PREFIX}/etc/lcdexec.conf.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
