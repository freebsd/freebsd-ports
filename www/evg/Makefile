# New ports collection makefile for:	evg
# Date created:		19 April 1999
# Whom:			Dima Sivachenko	<dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	evg
PORTVERSION=	1.01
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.uni-klu.ac.at/pub/projects/evg/	\
		http://www.chg.ru/~dima/

MAINTAINER=	dima@Chg.RU

RUN_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS+=	xv:${PORTSDIR}/graphics/xv

NO_BUILD=	yes

post-patch:
		@ ${MV} ${WRKSRC}/evg.py ${WRKSRC}/evg.py.sed
		@ ${SED} -e 's%!!PREFIX!!%${PREFIX}%' < ${WRKSRC}/evg.py.sed \
		  > ${WRKSRC}/evg.py.sed1
		@ ${SED} -e 's%!!XPREF!!%${X11BASE}%' < ${WRKSRC}/evg.py.sed1 \
		  > ${WRKSRC}/evg.py

do-install:
		@ ${MKDIR} ${PREFIX}/lib/python1.5/site-packages
		@ ${INSTALL_SCRIPT} ${WRKSRC}/eclipthtml.py ${PREFIX}/lib/python1.5/site-packages
		@ ${INSTALL_SCRIPT} ${WRKSRC}/evg.py ${PREFIX}/bin

.include <bsd.port.mk>
