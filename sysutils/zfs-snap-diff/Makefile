# $FreeBSD$

PORTNAME=	zfs-snap-diff
PORTVERSION=	0.0.9
CATEGORIES=	sysutils

MAINTAINER=	ben.lavery@hashbang0.com
COMMENT=	View ZFS snapshot differences via a web browser

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/src/github.com/sergi/go-diff/LICENSE.txt
LICENSE_FILE_MIT=	${WRKSRC}/src/github.com/j-keck/${PORTNAME}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	j-keck:DEFAULT \
		sergi:go_diff
GH_PROJECT=	go-diff:go_diff
GH_TAGNAME=	f7fcaad:go_diff
GH_SUBDIR=	src/github.com/j-keck/zfs-snap-diff \
		src/github.com/sergi/go-diff:go_diff

USES=		go

PLIST_FILES=	bin/zfs-snap-diff

STRIP=		# stripping can break go binaries

.include <bsd.port.mk>
