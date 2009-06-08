# New ports collection makefile for:	kdeedu3
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	kdeedu
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	1
CATEGORIES?=	misc kde
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org
COMMENT=	Collection of entertaining, educational programs for KDE

LIB_DEPENDS=	boost_python:${PORTSDIR}/devel/boost-python

CONFLICTS+=	kwordquiz-[0-9]* kgeography-[0-9]*

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_XORG=	xpm
USE_GMAKE=	yes
USE_AUTOTOOLS=  libtool:15

CONFIGURE_ARGS+=--enable-libusb=${LOCALBASE} \
		--disable-ocamlsolver

USE_LDCONFIG=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
.endif

pre-configure:
	${REINPLACE_CMD} \
	-e 's|pylibdir in.*|pylibdir in "${LOCALBASE}/lib" \\|g' \
	${WRKSRC}/configure

.include <bsd.port.post.mk>
