# Created by: Yonatan@Xpert.com
# $FreeBSD$

PORTNAME=	fortune-mod-bofh
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	LOCAL/flz/${PORTNAME} \
		http://www.irq.org/
DISTFILES=	bofh-fortune-mod${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	onatan@gmail.com
COMMENT=	Compilation of excuses from the "Bastard Operator From Hell"

BUILD_DEPENDS=	fortune_strfile:misc/fortune_strfile
STRFILE=	${LOCALBASE}/bin/fortune_strfile

WRKSRC=		${WRKDIR}/bofh-fortune-mod2.0

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

do-build:
	${STRFILE} ${WRKSRC}/bofh

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/bofh* \
		${STAGEDIR}${PREFIX}/share/games/fortune

.include <bsd.port.mk>
