# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	cryptlib_py
PORTVERSION=	3.4.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.franken.de/pub/crypt/cryptlib/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	cl${PORTVERSION:S/.//g}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pythin binding for cryptlib

BROKEN=		unfetchable

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	i386 amd64 armv6 armv7

USES=		python:2.7 zip:infozip
USE_PYTHON=	distutils autoplist

LIB_DEPENDS+=	libcl.so:security/cryptlib

BUILD_WRKSRC=	${WRKSRC}/bindings
INSTALL_WRKSRC=	${BUILD_WRKSRC}
NO_WRKSUBDIR=	yes

.include <bsd.port.mk>
