# New ports collection makefile for:	mkvtoolnix
# Date created:		Tue Feb 24 02:09:12 UTC 2004
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mkvtoolnix
PORTVERSION=	1.4.1
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.bunkus.org/videotools/mkvtoolnix/sources/ \
		http://www.bunkus.org/videotools/mkvtoolnix/sources/old/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Tools to extract from/get info about/create Matroska media streams

BUILD_DEPENDS=	${LOCALBASE}/lib/libmatroska.a:${PORTSDIR}/multimedia/libmatroska \
		${LOCALBASE}/lib/libebml.a:${PORTSDIR}/textproc/libebml
LIB_DEPENDS=	FLAC.7:${PORTSDIR}/audio/flac \
		expat.5:${PORTSDIR}/textproc/expat2 \
		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

MAN1=		base64tool.1 mkvextract.1 mkvinfo.1 mkvmerge.1
PLIST_FILES=	bin/base64tool bin/mkvextract bin/mkvinfo bin/mkvmerge

WXGTK_CONFIG=	wxgtk2-2.4-config

.include <bsd.port.pre.mk>

.ifndef(WITHOUT_WXGTK)
LIB_DEPENDS+=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2

MAN1+=		mmg.1
PLIST_FILES+=	bin/mmg
.endif

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
CFLAGS+= -DNO_WSTRING
.endif

pre-everything::
.ifndef(WITHOUT_WXGTK)
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> You can disable wxGTK2 support by defining"
	@${ECHO_MSG} "===>  WITHOUT_WXGTK"
	@${ECHO_MSG} "===>"
.endif

post-patch:
# disable GNU auto* tools
	@${FIND} ${WRKSRC} -type f -name "Makefile.in" | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E -e \
		's!^(ACLOCAL|AUTOCONF|AUTOMAKE|AUTOHEADER).+$$!\1=${TRUE}!'
	@${REINPLACE_CMD} -e 's|wx-config|${WXGTK_CONFIG}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/src/common/os.cpp

.include <bsd.port.post.mk>
