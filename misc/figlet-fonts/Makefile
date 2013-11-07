# Created by: dd
# $FreeBSD$

PORTNAME=	figlet-fonts
PORTVERSION=	20121202
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.figlet.org/pub/figlet/fonts/
DISTFILES=	contributed.tar.gz international.tar.gz
DIST_SUBDIR=	figlet

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Assorted fonts for the figlet(6) program

RUN_DEPENDS=    figlet:${PORTSDIR}/misc/figlet

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/share/figlet
PLIST_SUB=	DATADIR=${DATADIR:S|^${PREFIX}/||}

post-extract:
	@cd ${WRKDIR}/contributed && \
		${TAR} xf Obanner-canon.tgz -C ${WRKDIR}/contributed/ && \
		${MV} ./Obanner-canon/* ${WRKDIR}/contributed/ && \
		${RMDIR} ./Obanner-canon && \
		${RM} -f Obanner-canon.tgz && \
		${TAR} xf Obanner.tgz -C ${WRKDIR}/contributed/ && \
		${MV} ./Obanner/* ${WRKDIR}/contributed/ && \
		${RMDIR} ./Obanner && \
		${RM} -f Obanner.tgz && \
		${MV} ./C64-fonts/* ${WRKDIR}/contributed/ && \
		${RMDIR} ./C64-fonts && \
		${MV} ./bdffonts/* ${WRKDIR}/contributed/ && \
		${RMDIR} ./bdffonts
	@cd ${WRKDIR}/international && \
		${TAR} xf cjkfonts.tar.gz -C ${WRKDIR}/international/ && \
		${RM} -f cjkfonts.tar.gz
	@${RM} -f ${WRKDIR}/contributed/banner.flf

do-install:
.for f in contributed international
	@cd ${WRKDIR}/${f} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
