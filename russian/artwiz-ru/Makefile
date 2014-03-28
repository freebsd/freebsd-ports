# Created by: Roman Bogorodskiy <bogorodskiy@inbox.ru>
# $FreeBSD$

PORTNAME=	artwiz-ru
PORTVERSION=	20041031
PORTREVISION=	2
CATEGORIES=	russian x11-fonts
MASTER_SITES=	http://dev.gentoo.org/~sergey/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	novel
DISTNAME=	artwiz_ru

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Russian Artwiz fonts

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USES=		tar:bzip2
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/fonts
PKGMESSAGE=	${WRKDIR}/pkg-message

FONTDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}

post-patch:
	@${SED} -e 's,LOCALBASE,${LOCALBASE},g' \
		${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${STAGEDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf ${STAGEDIR}${FONTDIR}

.include <bsd.port.mk>
