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
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER?=	ports@FreeBSD.org

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14
LIB_DEPENDS+=	noatun.0:${PORTSDIR}/audio/kdemultimedia2 \
		SDL-1.1.3:${PORTSDIR}/devel/sdl12

WITH_SDL=	yes
USE_KDEBASE_VER=2
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST_SUB+=	RM=${RM}
CONFIGURE_ENV+=	SDL_CONFIG="${LOCALBASE}/bin/sdl11-config"

.include "${.CURDIR}/../../x11/kde2/Makefile.kde"

.include <bsd.port.pre.mk>

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
	find ${WRKSRC} -name Makefile.in | xargs ${PERL} -pi -e \
		"s@sdl-config@${LOCALBASE}/bin/sdl11-config@g"

.include <bsd.port.post.mk>
