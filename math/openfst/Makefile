# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	openfst
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.openfst.org/twiki/pub/FST/FstDownload/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Library for working with weighted finite-state transducers (FSTs)

LICENSE=	APACHE20

USE_GCC=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-compact-fsts --enable-const-fsts --enable-far --enable-lookahead-fsts --enable-pdt

post-patch:
	${REINPLACE_CMD} -e s#-ldl## ${WRKSRC}/src/extensions/far/Makefile.in ${WRKSRC}/src/extensions/pdt/Makefile.in ${WRKSRC}/src/bin/Makefile.in ${WRKSRC}/src/test/Makefile.in

.include <bsd.port.mk>
