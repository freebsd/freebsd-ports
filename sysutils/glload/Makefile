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
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
ALL_TARGET=	glload

PLIST_FILES=	bin/glload

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glload ${PREFIX}/bin

.include <bsd.port.mk>
