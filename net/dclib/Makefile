# New ports collection makefile for:    dclib
# Date created:                         Wed 10 Jul 2002
# Whom: Sverrir Valgeirsson <e96sv@yahoo.se> and
#	Amar Takhar <verm@drunkmonk.net> et al
#
# $FreeBSD$
#

PORTNAME=	dclib
PORTVERSION=	0.2.18
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/dcgui/ \
		http://ftp.kde.com/Networking_Internet/File_Sharing/Direct_Connect_4_Linux/ \
		ftp://ftp.kde.com/Networking_Internet/File_Sharing/Direct_Connect_4_Linux/

MAINTAINER=	brueffer@phoenix-systems.de
COMMENT=	Direct connect interface library for dcgui

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g; s/-pedantic //g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
