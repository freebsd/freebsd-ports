# Created by: dd
# $FreeBSD$

PORTNAME=	figlet-fonts
PORTVERSION=	20121202
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.figlet.org/pub/figlet/fonts/
DISTFILES=	contributed.tar.gz international.tar.gz
DIST_SUBDIR=	figlet

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Assorted fonts for the figlet(6) program

RUN_DEPENDS=	figlet:misc/figlet

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/share/figlet
PLIST_SUB=	DATADIR=${DATADIR:S|^${PREFIX}/||}

post-extract:
	@cd ${WRKSRC}/contributed && \
		${TAR} xf Obanner-canon.tgz -C ${WRKSRC}/contributed/ && \
		${MV} ./Obanner-canon/* ${WRKSRC}/contributed/ && \
		${RMDIR} ./Obanner-canon && \
		${RM} -f Obanner-canon.tgz && \
		${TAR} xf Obanner.tgz -C ${WRKSRC}/contributed/ && \
		${MV} ./Obanner/* ${WRKSRC}/contributed/ && \
		${RMDIR} ./Obanner && \
		${RM} -f Obanner.tgz && \
		${MV} ./C64-fonts/* ${WRKSRC}/contributed/ && \
		${RMDIR} ./C64-fonts && \
		${MV} ./bdffonts/* ${WRKSRC}/contributed/ && \
		${RMDIR} ./bdffonts
	@cd ${WRKSRC}/international && \
		${TAR} xf cjkfonts.tar.gz -C ${WRKSRC}/international/ && \
		${RM} -f cjkfonts.tar.gz
	@${RM} -f ${WRKSRC}/contributed/banner.flf

do-install:
.for f in contributed international
	@cd ${WRKSRC}/${f} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
