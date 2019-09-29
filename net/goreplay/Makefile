# $FreeBSD$

PORTNAME=	goreplay
PORTVERSION=	0.16.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tool for capturing and replaying live HTTP traffic

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	buger
GH_TUPLE=	google:gopacket:v1.1.16:gopacket/vendor/github.com/google/gopacket \
		mattbaird:elastigo:34c4c4d:elastigo/vendor/github.com/mattbaird/elastigo \
		bitly:go-hostpool:d0e59c2:hostpool/vendor/github.com/bitly/go-hostpool \
		araddon:gou:50a94aa:gou/vendor/github.com/araddon/gou
GH_SUBDIR=	src/github.com/buger/goreplay

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
