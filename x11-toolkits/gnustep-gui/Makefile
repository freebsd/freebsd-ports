# New ports collection makefile for:    gnustep-gui
# Date created:         19 April 2001
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep-gui
PORTVERSION=	0.9.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
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
USE_GNUSTEP=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_BASE=	yes
MAKEFILE=
MAKE_FLAGS+=	OPTFLAG="${CFLAGS}"
BREAKS_IF_PEDANTIC=	yes
USE_REINPLACE=	yes

post-extract:
.for file in config.guess config.sub install-sh
	@${CP} ${PREFIX}/System/Makefiles/${file} ${WRKSRC}
.endfor

pre-configure:
	${REINPLACE_CMD} -e "s|-lphread|${PTHREAD_LIBS}|" -e "s|CFLAGS =|CFLAGS+=|" \
		-e "s|-Wall|-Wall ${PTHREAD_CFLAGS:S=""==}|" \
		${WRKSRC}/Tools/gsnd/portaudio/pa_unix_oss/Makefile
.if !defined(NOPORTDOCS)
	${REINPLACE_CMD} -e "s|doc=no|doc=yes|" ${WRKSRC}/GNUmakefile
.endif

test:
	@(cd ${WRKSRC}/Tools/gsnd/portaudio/pa_unix_oss && \
		${GMAKE} && ./patest)

.include <bsd.port.mk>
