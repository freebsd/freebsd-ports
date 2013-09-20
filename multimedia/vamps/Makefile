# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vamps
PORTVERSION=	0.99.2
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/Vamps/${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	High performance tool to transcode DVD videos to a smaller size

LIB_DEPENDS=	dvdread.4:${PORTSDIR}/multimedia/libdvdread

USE_GMAKE=	yes

CFLAGS+=	-DHAVE_BUILTIN_EXPECT \
		-I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib \
		${PTHREAD_LIBS}

PROGRAM_FILES=	\
		play_cell/play_cell \
		vamps/vamps

PLIST_FILES=	${PROGRAM_FILES:H:S,^,bin/,}

NO_STAGE=	yes
do-install:
.for program in ${PROGRAM_FILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${program} ${PREFIX}/bin/${program:H}
.endfor

.include <bsd.port.mk>
