# New ports collection makefile for:    gnustep-gui
# Date created:         19 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-gui
.if defined(WITH_GNUSTEP_DEVEL)
PORTVERSION=	0.8.8
.else
PORTVERSION=	0.8.5
.endif
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNUSTEP} \
		ftp://ftp.gnustep.org/pub/gnustep/%SUBDIR%/
MASTER_SITE_SUBDIR=	core

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep GUI library

LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
LIB_DEPENDS+=	audiofile.0:${PORTSDIR}/audio/libaudiofile

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--with-tiff-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-tiff-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-jpeg-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-jpeg-include=${LOCALBASE}/include
USE_GMAKE=	yes
MAKEFILE=
MAKE_FLAGS+=	OPTFLAG="${CFLAGS}"
BREAKS_IF_PEDANTIC=	yes
EXTRA_FIX=		${WRKSRC}/Tools/gsnd/portaudio/pa_unix_oss/Makefile

.include <bsd.port.pre.mk>

USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_BASE=	yes
.include "${PORTSDIR}/devel/gnustep/bsd.gnustep.mk"

post-extract:
.for file in config.guess config.sub install-sh
	@${CP} ${PREFIX}/System/Makefiles/${file} ${WRKSRC}
.endfor

pre-configure:
	@ ${MV} ${EXTRA_FIX} ${EXTRA_FIX}.sed
	${SED} -e "s=-lphread=${PTHREAD_LIBS}=" -e "s;CFLAGS =;CFLAGS+=;" \
		-e "s;-Wall;-Wall ${PTHREAD_CFLAGS:S=""==};" \
		${EXTRA_FIX}.sed > ${EXTRA_FIX}

test:
	@(cd ${WRKSRC}/Tools/gsnd/portaudio/pa_unix_oss && \
		${GMAKE} && ./patest)

.include <bsd.port.post.mk>
