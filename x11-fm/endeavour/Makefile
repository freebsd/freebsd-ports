# New ports collection makefile for:	endeavour
# Date created:		7 Oct 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	endeavour
PORTVERSION=	1.13.0
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical file manager and image viewer aimed towards new users

PLIST_FILES=	bin/endeavour
USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	imlib
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	unix
MAKE_ARGS=	PREFIX="${PREFIX}" CC="${CC}" CPP="${CXX}" \
		CFLAGS="${CFLAGS} -D__USE_BSD -DUSE_XSHM -DUSE_IMLIB" \
		INC_DIRS="`imlib-config --cflags` -I${X11BASE}/include" \
		LIBS="`imlib-config --libs` -lXpm" \
		LIB_DIRS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 440003 || ${OSVERSION} >= 500000 && ${OSVERSION} < 500027
CFLAGS+=	-DNEED_STRCASESTR
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|make |\$$\(MAKE\) |g' ${WRKSRC}/Makefile
	@${FIND} ${WRKSRC}/endeavour -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|#include <malloc.h>||g ; \
		 s|#include <asm/types.h>||g ; \
		 s|#include <sys/bitypes.h>||g ; \
		 s|umode_t|unsigned short|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/endeavour/endeavour ${PREFIX}/bin

.include <bsd.port.post.mk>
