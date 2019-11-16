# $FreeBSD$

PORTNAME=	gotop
DISTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal based graphical activity monitor inspired by gtop and vtop

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	cjbassi
GH_TUPLE=	docopt:docopt.go:ee0de3b:docopt/src/github.com/docopt/docopt-go \
		shirou:gopsutil:v2.19.01:gopsutil/src/github.com/shirou/gopsutil \
		golang:sys:37707fd:sys/src/golang.org/x/sys

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
