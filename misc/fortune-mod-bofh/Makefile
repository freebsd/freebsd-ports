# Created by: Yonatan@Xpert.com
# $FreeBSD$

PORTNAME=	fortune-mod-bofh
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL:S/$/:freebsd/} \
		http://www.irq.org/:original
MASTER_SITE_SUBDIR=	flz/${PORTNAME}/:freebsd
DISTFILES=	bofh-fortune-mod${PORTVERSION}${EXTRACT_SUFX}:original,freebsd

MAINTAINER=	onatan@gmail.com
COMMENT=	Compilation of excuses from the "Bastard Operator From Hell"

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/bofh-fortune-mod2.0

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

STRFILE=	/usr/games/strfile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/bofh ${STAGEDIR}${PREFIX}/share/games/fortune
	@${STRFILE} ${STAGEDIR}${PREFIX}/share/games/fortune/bofh

.include <bsd.port.mk>
