# New ports collection makefile for:    dclib
# Date created:                         Wed 10 Jul 2002
# Whom:	Sverrir Valgeirsson <e96sv@yahoo.se> and
#	Amar Takhar <verm@drunkmonk.net> et al
#
# $FreeBSD$
#

PORTNAME=	dcgui
PORTVERSION=	0.1.11
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://ftp.kde.com/Networking_Internet/File_Sharing/Direct_Connect_4_Linux/ \
		http://download.berlios.de/dcgui/ \
		ftp://ftp.kde.com/Networking_Internet/File_Sharing/Direct_Connect_4_Linux/ \
		http://dc.ketelhot.de/files/dcgui/unstable/source/
MASTER_SITE_SUBDIR=	dc-gui
DISTNAME=	dcgui-0.1beta11

MAINTAINER=	e96sv@yahoo.se

LIB_DEPENDS=	dc.0:${PORTSDIR}/net/dclib \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_X_PREFIX=	yes
USE_QT_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libdc=${LOCALBASE} \
		--with-xml-prefix=${LOCALBASE} \
		--program-prefix=

post-patch:
# Fix libxml2 test
# And, do not add optimizations because it might break some ARCHs, e.g.,
# alpha
	@${REINPLACE_CMD} -e 's@xmlversion.h@libxml/xmlversion.h@; \
		s@-O2@@' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
