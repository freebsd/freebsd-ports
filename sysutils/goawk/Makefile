PORTNAME=	goawk
DISTVERSIONPREFIX=	v
DISTVERSION=	1.29.1
PORTREVISION=	6
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	AWK interpreter written in Go
WWW=		https://github.com/benhoyt/goawk

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	benhoyt
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
