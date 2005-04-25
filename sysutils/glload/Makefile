# New ports collection makefile for:	glload
# Date created:			04 Dec 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glload
PORTVERSION=	0.4.2
CATEGORIES=	sysutils
MASTER_SITES=	http://reality.exsgi.org/eile/misc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gl base load monitor

LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/libglut

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_GL=		yes
MAKEFILE=	Makefile.FreeBSD
MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS} -I${X11BASE}/include -DFreeBSD ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${X11BASE}/lib ${PTHREAD_LIBS}" \
		OBJS="get_load.o trackball.o glload.o texture.o screenShot.o"
ALL_TARGET=	glload

PLIST_FILES=	bin/glload

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glload ${PREFIX}/bin

.include <bsd.port.mk>
