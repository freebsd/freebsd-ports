# $FreeBSD$

PORTNAME=	zfs-snap-diff
PORTVERSION=	0.0.10
CATEGORIES=	sysutils

MAINTAINER=	ben.lavery@hashbang0.com
COMMENT=	View ZFS snapshot differences via a web browser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/src/github.com/j-keck/${PORTNAME}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	j-keck:DEFAULT \
		sergi:go_diff
GH_PROJECT=	go-diff:go_diff
GH_TAGNAME=	97b2266:go_diff
GH_SUBDIR=	src/github.com/j-keck/zfs-snap-diff \
		src/github.com/sergi/go-diff:go_diff

PLIST_FILES=	bin/zfs-snap-diff

.include <bsd.port.mk>
