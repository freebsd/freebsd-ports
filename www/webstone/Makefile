# New ports collection makefile for:   webstone
# Date created:        25 March 1997
# Whom:                Soren Dossing <sauber@netcom.com>
#
# $FreeBSD$
#

PORTNAME=	webstone
PORTVERSION=	2.5
CATEGORIES=	www benchmarks
MASTER_SITES=	http://www.mindcraft.com/webstone/
DISTNAME=	ws25_src
EXTRACT_SUFX=	.tgz 

MAINTAINER=	fortune@n.jpn.ph
COMMENT=	World wide web server benchmarking

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/WebStone2.5/src
ALL_TARGET=	install
NO_INSTALL_MANPAGES=	yes

do-install:
	@${RM} ${WRKSRC}/../bin/runs/keepme
	@${RMDIR} ${WRKSRC}/../bin/runs
	@${MKDIR} ${PREFIX}/webstone/bin
	@${MKDIR} ${PREFIX}/webstone/conf
	@${MKDIR} ${PREFIX}/webstone/lgm
	${INSTALL_SCRIPT} ${WRKSRC}/../bin/* ${PREFIX}/webstone/bin
	${INSTALL_SCRIPT} ${WRKSRC}/../lgm/* ${PREFIX}/webstone/lgm
	${INSTALL_DATA} ${WRKSRC}/../conf/* ${PREFIX}/webstone/conf
	${INSTALL_SCRIPT} ${WRKSRC}/../webstone  ${PREFIX}/webstone
	@${MKDIR} ${WRKSRC}/../bin/runs
	@${TOUCH} ${WRKSRC}/../bin/runs/keepme
.for file in webclient webmaster genrand
	${STRIP_CMD} ${PREFIX}/webstone/bin/${file}
.endfor
.for file in ws20_cgi ws25_cgi
	${STRIP_CMD} ${PREFIX}/webstone/lgm/${file}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
