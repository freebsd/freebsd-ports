# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	m2tstoavi
PORTVERSION=	2009121901
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.olmosconsulting.com/ http://meatwad.mouf.net/~steve/
DISTNAME=	m2ts

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Utility which eases conversion of AVCHD (m2ts) to AVI

RUN_DEPENDS=	xporthdmv:${PORTSDIR}/multimedia/xporthdmv \
		ldecod:${PORTSDIR}/multimedia/jmref \
		ffmpeg:${PORTSDIR}/multimedia/ffmpeg

NO_STAGE=	yes
do-build:
	${DO_NADA}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/m2tstoavi.alkayata ${PREFIX}/bin/m2tstoavi.alkayata
	${INSTALL_SCRIPT} ${WRKSRC}/m2tstoavi.fifo ${PREFIX}/bin/m2tstoavi.fifo
	${INSTALL_SCRIPT} ${WRKSRC}/m2tstoavi.nofifo ${PREFIX}/bin/m2tstoavi.nofifo
	${INSTALL_SCRIPT} ${WRKSRC}/m2tstoavi.mencoder ${PREFIX}/bin/m2tstoavi.mencoder
	${LN} -s ${PREFIX}/bin/m2tstoavi.mencoder ${PREFIX}/bin/m2tstoavi

.include <bsd.port.mk>
