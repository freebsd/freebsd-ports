PORTNAME=		fortune-mod-mormon
DISTVERSION=		1.1.0
CATEGORIES=		misc
MASTER_SITES=		SF/mormon/fortune-mod-scriptures/${DISTVERSION}/

MAINTAINER=		ziaee@FreeBSD.org
COMMENT=		LDS Scriptures in fortune file format
WWW=			https://scriptures.nephi.org

LICENSE=		PD
LICENSE_FILE=		${WRKSRC}/COPYING

USES=			tar:bzip2
CONFLICTS_INSTALL=	fortune-mod-bible fortune-mod-psalms

MODS=			acts aof bible dc eccl epistles gospels isaiah \
			mormon nt ot pgp proverbs psalms scriptures

PLIST_FILES=		${MODS:S,^,share/games/fortune/,} \
			${MODS:S,^,share/games/fortune/,:S,$,.dat,}

do-build:
.for i in ${MODS}
	${RM} ${WRKSRC}/mods/${i}.dat
	strfile ${WRKSRC}/mods/${i}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/mods/* ${STAGEDIR}${PREFIX}/share/games/fortune

.include <bsd.port.mk>
