# New ports collection makefile for:	addons for kde
# Date created:				7 August 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kdeaddons
PORTVERSION=	2.2.2
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	Attic/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	ports@FreeBSD.org

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14
LIB_DEPENDS+=	noatun.0:${PORTSDIR}/audio/kdemultimedia2 \
		SDL-1.1.4:${PORTSDIR}/devel/sdl12

USE_REINPLACE=	yes
WITH_SDL=	yes
USE_KDEBASE_VER=2
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST_SUB+=	RM=${RM}
CONFIGURE_ENV+=	SDL_CONFIG="${LOCALBASE}/bin/sdl11-config"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500029
_NO_KDE_OBJPRELINK=yes
.endif

.include "${.CURDIR}/../../x11/kde2/Makefile.kde"

pre-configure:
	${MKDIR} ${WRKSRC}/auto-bin
.for AC in autoconf autoheader
	${LN} -sf ${LOCALBASE}/bin/${AC}213 ${WRKSRC}/auto-bin/${AC}
.endfor
.for AM in automake aclocal
	${LN} -sf ${LOCALBASE}/bin/${AM}14 ${WRKSRC}/auto-bin/${AM}
.endfor
	cd ${WRKSRC} && env PATH=${WRKSRC}/auto-bin:$$PATH \
		${GMAKE} -f Makefile.cvs
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		"s@sdl-config@${LOCALBASE}/bin/sdl11-config@g"

.include <bsd.port.post.mk>
