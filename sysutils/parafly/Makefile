PORTNAME=	parafly
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0	# Test new versions with Trinity before upgrading
PORTREVISION=	8
PORTEPOCH=	1	# SourceForge version was 2013.01.21
CATEGORIES=	sysutils

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Process multiple commands in parallel on a single server

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes

GH_PROJECT=	ParaFly

GNU_CONFIGURE=	yes

CXXFLAGS+=	-fopenmp
LDFLAGS+=	-fopenmp

PLIST_FILES=	bin/ParaFly

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USES+=		compiler:gcc-c++11-lib
.endif

.include <bsd.port.mk>
