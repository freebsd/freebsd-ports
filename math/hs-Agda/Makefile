# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	Agda
PORTVERSION=	2.5.4.2
PORTREVISION=	1
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Dependently typed functional programming language and proof assistant

BROKEN=		Doesn't build with recent GHC

USES=		cabal

EXECUTABLE=	agda-mode agda

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	DATADIR=${DATADIR}

.include <bsd.port.mk>
