# New ports collection makefile for:   surfraw
# Date created:                2000-08-03
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	surfraw
PORTVERSION= 	0.5.7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	surfraw

MAINTAINER=	naddy@mips.inka.de

GNU_CONFIGURE=	yes

ELVI=	W altavista appwatch ask austlii cite cnn currency deja excite \
	fast freshmeat ftpsearch google ircsearch linuxdoc netbsd \
	newscientist pubmed raging rhyme slashdot sundocs sunsolve \
	thesaurus translate webster wetandwild xxx yahoo \

do-install:
.for i in ${ELVI}
	${INSTALL_SCRIPT} ${WRKSRC}/elvi/${i} ${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/surfraw ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/surfraw-netscape-remote ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/surfraw/
	${INSTALL_DATA} ${WRKSRC}/elvi/surfraw_elvi.list ${PREFIX}/share/surfraw/
	${INSTALL_DATA} ${WRKSRC}/surfraw.conf ${PREFIX}/etc/surfraw.conf.sample

.include <bsd.port.mk>
