# New ports collection makefile for:	artwiz-ru
# Date created:		2004-10-31
# Whom:			Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	artwiz-ru
PORTVERSION=	20041031
CATEGORIES=	russian x11-fonts
MASTER_SITES=	http://dev.gentoo.org/~sergey/
DISTNAME=	artwiz_ru

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Russian Artwiz fonts

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/fonts
PKGMESSAGE=	${WRKDIR}/pkg-message

FONTDIR=	${X11BASE}/lib/X11/fonts/${PORTNAME}

post-patch:
	@${SED} -e 's,X11BASE,${X11BASE},g' ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

do-install:
	${MKDIR} ${FONTDIR}
	for f in ${WRKSRC}/*; do \
		${INSTALL_DATA} $$f ${FONTDIR}; \
		done

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
