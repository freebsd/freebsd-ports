# $FreeBSD$

PORTNAME=	miller
DISTVERSIONPREFIX=	v
DISTVERSION=	5.3.0
CATEGORIES=	textproc

MAINTAINER=	jungleboogie0+mlr@gmail.com
COMMENT=	Sed/awk/cut/join/sort for name-indexed data such as CSV

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_aarch64=	Fails to compile: undefined reference to .mcount

USES=		autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	johnkerl
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/mlr man/man1/mlr.1.gz

.include <bsd.port.mk>
