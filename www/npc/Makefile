# New ports collection makefile for:	npc.cgi
# Version required:	0.83
# Date created:		3 December 1998
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $Id$
#

DISTNAME=	npc-0.83
CATEGORIES=	www
MASTER_SITES=	http://www2.biglobe.ne.jp/%7Enir/soft/

MAINTAINER=	yasuf@big.or.jp

WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKE_ARGS=	INDEX_DIR="${INDEX_DIR}"

INDEX_DIR=	${PREFIX}/etc/npc

do-install:
	${MKDIR} ${PREFIX}/www/cgi-bin
	cd ${WRKSRC}; \
	    ${INSTALL_PROGRAM} npc.cgi ${PREFIX}/www/cgi-bin
	${MKDIR} ${PREFIX}/share/examples/npc
	cd ${WRKSRC}/../conf; \
	    ${INSTALL_DATA} sample1.idx sample2.idx ${PREFIX}/share/examples/npc
	${MKDIR} ${INDEX_DIR}

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
