# New ports collection makefile for:	mpeg4ip-libmp4v2
# Date created:		28 Sep 2004
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpeg4ip
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-libmp4v2

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Mpeg-4 library and tools from mpeg4ip

USE_GMAKE=	yes
USE_GNOME=	gnometarget
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

BUILD_WRKSRC=	${WRKSRC}/lib/mp4v2
INSTALL_WRKSRC=	${WRKSRC}/lib/mp4v2

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/systems.h)
BROKEN=	"Please remove older version of faad before attempting to build ${PORTNAME}"
.endif

.if ${OSVERSION} < 500000
CFLAGS+=	-O2
.endif

post-patch:
# Speed up configure by not using 2 unneeded configure scripts.
	@${ECHO_CMD} "" > ${WRKSRC}/lib/rtp/configure
	@${ECHO_CMD} "" > ${WRKSRC}/lib/SDLAudio/configure
	@${REINPLACE_CMD} \
		-e 's|>&/|>/|; s|-Wmissing-declarations||; \
			s|-Wmissing-prototypes||' \
			${WRKSRC}/configure
pre-build:
	@cd ${WRKSRC}/lib/gnu && ${MAKE}

post-install:
.for i in include/mpeg4ip.h include/mpeg4ip_version.h mpeg4ip_config.h
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/include
.endfor

.include <bsd.port.post.mk>
