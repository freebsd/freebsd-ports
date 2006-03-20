# New ports collection makefile for:	vamps
# Date created:		Fri Dec 16 04:38:13 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vamps
PORTVERSION=	0.98
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	vamps

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	High performance tool to transcode DVD videos to a smaller size

LIB_DEPENDS=	dvdread.3:${PORTSDIR}/multimedia/libdvdread

CONFLICTS=	lxdvdrip-{{0.,1.[0-3],1.4[0-7]}*

USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
MAKE_ENV=	\
		CC="${CC}" \
		LDFLAGS="${LDFLAGS}"

CFLAGS+=	-DHAVE_BUILTIN_EXPECT \
		-I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib \
		${PTHREAD_LIBS}

PROGRAM_FILES=	\
		play_cell/play_cell \
		vamps/vamps

PLIST_FILES=	${PROGRAM_FILES:H:S,^,bin/,}

do-install:
.for program in ${PROGRAM_FILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${program} ${PREFIX}/bin/${program:H}
.endfor

.include <bsd.port.mk>
