PORTNAME=	miller
DISTVERSIONPREFIX=	v
DISTVERSION=	5.10.2
CATEGORIES=	textproc

MAINTAINER=	jungleboogie0+mlr@gmail.com
COMMENT=	Sed/awk/cut/join/sort for name-indexed data such as CSV, TSV and JSON

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	johnkerl

GNU_CONFIGURE=	yes
TEST_TARGET=	check

PLIST_FILES=	bin/mlr man/man1/mlr.1.gz

.include <bsd.port.mk>
