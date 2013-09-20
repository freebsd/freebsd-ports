# $FreeBSD$

PORTNAME=	gohufont
PORTVERSION=	2.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://font.gohu.org/

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Monospace bitmap font well suited for programming and terminal use

LICENSE=	WTFPL
LICENSE_NAME=	Do What The Fuck You Want To Public License, Version 2
LICENSE_FILE=	${WRKSRC}/COPYING-LICENSE
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

FONTDIR=	lib/X11/fonts/${PORTNAME}
NO_BUILD=	yes
PLIST_SUB+=	FONTDIR=${FONTDIR}

NO_STAGE=	yes
do-install:
	@${MKDIR} ${LOCALBASE}/${FONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${LOCALBASE}/${FONTDIR}

post-install:
	@cd ${LOCALBASE}/${FONTDIR} && mkfontdir
	@${CP} ${LOCALBASE}/${FONTDIR}/fonts.dir ${LOCALBASE}/${FONTDIR}/fonts.scale
	@command fc-cache -f -v ${LOCALBASE}/${FONTDIR}

.include <bsd.port.mk>
