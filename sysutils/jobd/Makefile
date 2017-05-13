# $FreeBSD$

PORTNAME=	jobd
PORTVERSION=	0.7.1
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	mark@heily.com
COMMENT=	Job management framework

LICENSE=	ISCL

BUILD_DEPENDS=	docbook2mdoc:textproc/docbook2mdoc

HAS_CONFIGURE=	YES
USE_GITHUB=	YES
USE_LDCONFIG=	YES
GH_ACCOUNT=	mheily

BROKEN_aarch64=		fails to compile: comparison of constant -1 with expression of type char is always true
BROKEN_mips64=		fails to configure: unrecognized command line option -std=c++11
BROKEN_powerpc64=	fails to configure: Unable to run configure in ./src/
BROKEN_sparc64=		fails to configure: unrecognized command line option -std=c++11

.include <bsd.port.mk>
