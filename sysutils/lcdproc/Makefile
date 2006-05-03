# New ports collection makefile for:	lcdproc
# Date created:				Sat Jun  1 20:03:41 EDT 2002
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	lcdproc
PORTVERSION=	0.5.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mmdolze@users.sourceforge.net
COMMENT=	A client/server suite for LCD devices

ONLY_FOR_ARCHS=	i386

USE_GCC=	3.2+
GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes
USE_RC_SUBR=	LCDd lcdproc

CONFIGURE_ARGS=	--enable-drivers=all \
		--disable-ldap \
		--disable-doxygen
CONFIGURE_ENV=	CFLAGS="${CFLAGS}"

MAN1=		lcdexec.1 lcdproc.1
MAN8=		LCDd.8

.if defined(WITH_USB)
LIB_DEPENDS+=		usb-0.1.8:${PORTSDIR}/devel/libusb
CONFIGURE_ARGS+=	--enable-libusb
PLIST_SUB+=		USB=""
.else
CONFIGURE_ARGS+=	--disable-libusb
PLIST_SUB+=		USB="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's!server/drivers!${PREFIX}/lib/lcdproc!' ${WRKSRC}/LCDd.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/LCDd.conf ${PREFIX}/etc/LCDd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/LCDclients.conf ${PREFIX}/etc/LCDclients.conf.sample

.include <bsd.port.mk>
