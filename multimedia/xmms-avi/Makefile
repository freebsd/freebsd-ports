# Ports collection makefile for:  xmms-avi
# Date created:			  Feb 6 2000
# Whom:				  Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-avi
PORTVERSION=	1.2.3
PORTREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	http://www.xmms.org/files/plugins/avi-xmms/ \
		ftp://ftp.sunet.se/pub/multimedia/xmms/plugins/avi-xmms/ \
		ftp://ftp.fu-berlin.de/unix/sound/xmms/plugins/avi-xmms/
DISTNAME=	avi-xmms-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An avifile based .avi and .asf file playback plugin for XMMS

DEPRECATED=     Distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

ONLY_FOR_ARCHS=	i386

USE_GNOME=	gtk12
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-win32-path=${LOCALBASE}/lib/win32
USE_LDCONFIG=	yes

PLIST_FILES=	lib/xmms/Input/libavixmms.so

post-patch:
	@${REINPLACE_CMD} \
		-e "s|-lc_r|${PTHREAD_LIBS}|g" \
		-e '/objformat=/s|=.*|=elf|' \
			${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-march=i586|@CXXFLAGS@|g ; \
		 s|-O2||g ; \
		 s|$$(CC_OPTS)|@CFLAGS@|g'

# This is to avoid libtool running ldconfig -m ${LOCALBASE}/lib/xmms/Input
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/libavixmms.so ${PREFIX}/lib/xmms/Input

.include <bsd.port.mk>
