# Created by: Pierre-Paul Lavoie <ppl@nbnet.nb.ca>
# $FreeBSD$

PORTNAME=	mbasecalc
PORTVERSION=	1.1
PORTREVISION=	7
CATEGORIES=	math
MASTER_SITES=	http://www.muquit.com/muquit/software/mbasecalc/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple calculator program inspired by basecalc

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

MAKE_ARGS=	INCLUDES="`fltk-config --cflags` -I." \
		LIBS="`fltk-config --ldflags`"

PLIST_FILES=	bin/mbasecalc

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mbasecalc ${PREFIX}/bin

.include <bsd.port.mk>
