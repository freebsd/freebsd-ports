# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	parafly
PORTVERSION=	2013.01.21
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	${PORTNAME}-r2013-01-21

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Process multiple commands in parallel on a single server

LICENSE=	BSD3CLAUSE

USES=		compiler:openmp tar:tgz

GNU_CONFIGURE=	yes

CXXFLAGS+=	-fopenmp
LDFLAGS+=	-fopenmp

PLIST_FILES=	bin/ParaFly

.include <bsd.port.mk>
