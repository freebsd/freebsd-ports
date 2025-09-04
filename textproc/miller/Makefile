PORTNAME=	miller
DISTVERSIONPREFIX=	v
DISTVERSION=	6.13.0
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	https://raw.githubusercontent.com/johnkerl/${PORTNAME}/${DISTVERSIONFULL}/:gomod
DISTFILES=	go.mod:gomod

MAINTAINER=	jungleboogie0+mlr@gmail.com
COMMENT=	Sed/awk/cut/join/sort for name-indexed data such as CSV, TSV and JSON
WWW=		https://johnkerl.org/miller/doc/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe go:modules
CPE_VENDOR=	johnkerl
GO_MODULE=	github.com/johnkerl/miller
GO_TARGET=	./cmd/mlr

USE_GITHUB=	yes
GH_ACCOUNT=	johnkerl

PLIST_FILES=	bin/mlr

.include <bsd.port.mk>
