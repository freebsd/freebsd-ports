# New ports collection makefile for: analog
# Date created:		October 21st 1996
# Whom:			jfitz
#
# $FreeBSD$
#

PORTNAME=	analog
PORTVERSION=	4.16
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.analog.cx/ \
		http://www.monash.edu.au/mirror/analog/ \
		http://analog.gsp.com/ \
		http://analog.barringtons.com/ \
		http://www.pomfret.net/mirror/analog/ \
		http://analog.org/loganalysis/ \
		http://www.skreamsoft.com/analogmirror/ \

MAINTAINER=	mharo@FreeBSD.org

MAKE_FLAGS=	-DPREFIX=${PREFIX} -f
ALL_TARGET=	analog

do-install:
	${MKDIR} ${PREFIX}/share/doc/analog
	${MKDIR} ${PREFIX}/share/analog/lang
	${MKDIR} ${PREFIX}/www/data/images
	${INSTALL_DATA} ${WRKSRC}/images/* ${PREFIX}/www/data/images
	${INSTALL_DATA} ${WRKSRC}/lang/* ${PREFIX}/share/analog/lang
	${INSTALL_PROGRAM} ${WRKSRC}/analog ${PREFIX}/bin
.if !exists(${PREFIX}/etc/analog.cfg)
	${INSTALL_DATA} ${WRKSRC}/analog.cfg ${PREFIX}/etc
.endif
	${INSTALL_DATA} ${WRKSRC}/analog.cfg ${PREFIX}/etc/analog.cfg-dist
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/analog
.endif

.include <bsd.port.mk>
