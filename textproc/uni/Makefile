# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uni
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Query the Unicode database from the commandline

LICENSE=	MIT

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	arp242

GO_PKGNAME=	arp242.net/uni
GH_TUPLE=	golang:sys:bd437916bb0e:golang_sys/vendor/golang.org/x/sys
#GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
