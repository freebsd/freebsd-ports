# New ports collection makefile for:    dclib
# Date created:                         Wed 10 Jul 2002
# Whom: Sverrir Valgeirsson <e96sv@yahoo.se> and
#	Amar Takhar <verm@drunkmonk.net> et al
#
# $FreeBSD$
#

PORTNAME=	dclib
PORTVERSION=	0.1.11
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://ftp.kde.com/Networking_Internet/File_Sharing/Direct_Connect_4_Linux/ \
		http://download.berlios.de/dcgui/ \
		ftp://ftp.kde.com/Networking_Internet/File_Sharing/Direct_Connect_4_Linux/ \
		http://dc.ketelhot.de/files/dcgui/unstable/source/
MASTER_SITE_SUBDIR=	dc-gui
DISTNAME=	dclib-0.1beta11

MAINTAINER=	e96sv@yahoo.se

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xml-prefix=${LOCALBASE}
INSTALLS_SHLIB= yes

post-patch:
# fix libxml2 test
# and, do not add optimizations because it might break some ARCHs, e.g.,
# alpha

	@${REINPLACE_CMD} -e 's@xmlversion.h@libxml/xmlversion.h@; \
		s@-O2@@; \
		s@%%LOCALBASE%%@${LOCALBASE}@g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e "s@Lu@llu@g" \
		${WRKSRC}/dclib/cstring.cpp \
		${WRKSRC}/dclib/cquerymanager.cpp
# malloc.h is deprecated in favor of stdlib.h
	@${FIND} ${WRKSRC} -type f -name "*.cpp" -o -name "*.h" | \
		${XARGS} -n 10 ${REINPLACE_CMD} 's|malloc\.h|stdlib.h|'

.include <bsd.port.mk>
