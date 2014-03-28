# Created by: Naresh Venkateshappa <nareshov@gmail.com>
# $FreeBSD$

PORTNAME=	fonts-indic
PORTVERSION=	2.1.5
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://gentoo.osuosl.org/distfiles/

MAINTAINER=	nareshov@gmail.com
COMMENT=	The Lohit family of Indic fonts

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

FONTSDIR=	lib/X11/fonts/${PORTNAME}/
PLIST_SUB+=	FONTSDIR=${FONTSDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*/*/*.ttf ${STAGEDIR}${PREFIX}/${FONTSDIR}

.include <bsd.port.mk>
