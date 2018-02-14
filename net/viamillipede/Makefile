# $FreeBSD$

PORTNAME=	viamillipede
PORTVERSION=	1.0
CATEGORIES=	cad
MASTER_SITES=	https://github.com/agokhale/viamillipede/

MAINTAINER=	ash_ports@aeria.net
COMMENT=	parallel TCP for pipe transport

LICENSE=	BSD

USE_GITHUB= 	yes
GH_ACCOUNT=	agokhale
GH_TAGNAME=	v0.5

BINS=		viamillipede

.PHONY= bad_ideas
bad_ideas: Makefile
	rm distinfo
	sudo make fetch 
	make makesum

.include <bsd.port.mk>

