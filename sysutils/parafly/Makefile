PORTNAME=	parafly
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0	# Test new versions with Trinity before upgrading
PORTREVISION=	9
PORTEPOCH=	1	# SourceForge version was 2013.01.21
CATEGORIES=	sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Process multiple commands in parallel on a single server
WWW=		https://github.com/ParaFly/ParaFly/releases

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes

GH_PROJECT=	ParaFly

GNU_CONFIGURE=	yes

CXXFLAGS+=	-fopenmp -std=c++11
LDFLAGS+=	-fopenmp

PLIST_FILES=	bin/ParaFly

.if !exists(/usr/include/omp.h)
USES+=		compiler:gcc-c++11-lib
.endif

.include <bsd.port.mk>
