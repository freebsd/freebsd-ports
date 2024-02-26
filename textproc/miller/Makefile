PORTNAME=	miller
DISTVERSIONPREFIX=	v
DISTVERSION=	5.10.2
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	jungleboogie0+mlr@gmail.com
COMMENT=	Sed/awk/cut/join/sort for name-indexed data such as CSV, TSV and JSON
WWW=		https://johnkerl.org/miller/doc/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		autoreconf cpe libtool
CPE_VENDOR=	johnkerl
USE_GITHUB=	yes
GH_ACCOUNT=	johnkerl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
TEST_TARGET=	check

PLIST_FILES=	bin/mlr share/man/man1/mlr.1.gz

.include <bsd.port.mk>
