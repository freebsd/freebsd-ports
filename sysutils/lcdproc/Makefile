# New ports collection makefile for:	lcdproc
# Date created:				Sat Jun  1 20:03:41 EDT 2002
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	lcdproc
PORTVERSION=	0.5.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bsdfan@nurfuerspam.de
COMMENT=	A client/server suite for LCD devices

ONLY_FOR_ARCHS=	i386 amd64

USE_AUTOTOOLS=	autoconf:262 automake:19 aclocal:19
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
USE_RC_SUBR=	LCDd lcdproc lcdexec

CONFIGURE_ARGS=	--enable-drivers="${LCDPROC_DRIVERS}" \
		--disable-dependency-tracking \
		--disable-doxygen

SUB_FILES=	pkg-message

MAN1=		lcdexec.1 lcdproc.1
MAN5=		lcdproc-config.5
MAN8=		LCDd.8

OPTIONS=	USB "Enable USB support" off

ACLOCAL_ARGS=

LCDPROC_DRIVERS=bayrad \
		CFontz \
		CFontz633 \
		CFontzPacket \
		CwLnx \
		curses \
		ea65 \
		EyeboxOne \
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
		sed1330 \
		sed1520 \
		serialPOS \
		serialVFD \
		sli \
		stv5730 \
		t6963 \
		text \
		tyan

.include <bsd.port.pre.mk>

.if defined(WITH_USB)
. if ${OSVERSION} < 800069
LIB_DEPENDS+=		usb-0.1.8:${PORTSDIR}/devel/libusb
CONFIGURE_ARGS+=	--with-libusb
. else
CONFIGURE_ARGS+=	--with-libusb=/usr
. endif
PLIST_SUB+=		USB=""
LCDPROC_DRIVERS+=IOWarrior \
		picolcd \
		shuttleVFD
.else
CONFIGURE_ARGS+=	--without-libusb
PLIST_SUB+=		USB="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's!server/drivers!${PREFIX}/lib/lcdproc!' ${WRKSRC}/LCDd.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/LCDd.conf ${PREFIX}/etc/LCDd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/clients/lcdproc/lcdproc.conf ${PREFIX}/etc/lcdproc.conf.sample
	${INSTALL_DATA} ${WRKSRC}/clients/lcdexec/lcdexec.conf ${PREFIX}/etc/lcdexec.conf.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
