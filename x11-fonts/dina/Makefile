# $FreeBSD$

PORTNAME=	dina
PORTVERSION=	2.89
CATEGORIES=	x11-fonts
MASTER_SITES=	LOCAL/rakuco

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	A monospace bitmap font, primarily aimed at programmers

# IANAL, but the license looks close enough to a standard BSD license that
# auto-accept and all the other permissions look like reasonable defaults here.
LICENSE=	custom
LICENSE_NAME=	Custom License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

FONTDIR=	lib/X11/fonts/${PORTNAME}
NO_BUILD=	yes
PLIST_SUB+=	FONTDIR=${FONTDIR}

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/${FONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${PREFIX}/${FONTDIR}

post-install:
	@cd ${PREFIX}/${FONTDIR} && mkfontdir
	@${CP} ${PREFIX}/${FONTDIR}/fonts.dir ${PREFIX}/${FONTDIR}/fonts.scale
	@command fc-cache -f -v ${PREFIX}/${FONTDIR}

.include <bsd.port.mk>
