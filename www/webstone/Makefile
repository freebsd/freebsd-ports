# Created by: Soren Dossing <sauber@netcom.com>
# $FreeBSD$

PORTNAME=	webstone
PORTVERSION=	2.5
CATEGORIES=	www benchmarks
MASTER_SITES=	http://www.mindcraft.com/webstone/
DISTNAME=	ws25_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	World wide web server benchmarking

USES=		tar:tgz
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/WebStone2.5/src
ALL_TARGET=	install

do-install:
	@${RM} ${WRKSRC}/../bin/runs/keepme
	@${RMDIR} ${WRKSRC}/../bin/runs
	@${MKDIR} ${STAGEDIR}${PREFIX}/webstone/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/webstone/conf
	@${MKDIR} ${STAGEDIR}${PREFIX}/webstone/lgm
	${INSTALL_SCRIPT} ${WRKSRC}/../bin/* ${STAGEDIR}${PREFIX}/webstone/bin
	${INSTALL_SCRIPT} ${WRKSRC}/../lgm/* ${STAGEDIR}${PREFIX}/webstone/lgm
	${INSTALL_DATA} ${WRKSRC}/../conf/* ${STAGEDIR}${PREFIX}/webstone/conf
	${INSTALL_SCRIPT} ${WRKSRC}/../webstone  ${STAGEDIR}${PREFIX}/webstone
	@${MKDIR} ${WRKSRC}/../bin/runs
	@${TOUCH} ${WRKSRC}/../bin/runs/keepme
.for file in webclient webmaster genrand
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/webstone/bin/${file}
.endfor
.for file in ws20_cgi ws25_cgi
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/webstone/lgm/${file}
.endfor

.include <bsd.port.mk>
