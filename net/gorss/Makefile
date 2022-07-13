# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	gorss
PORTVERSION=	0.3
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	net www

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple RSS/Atom reader written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	Lallassu

.include "${.CURDIR}/Makefile.deps"

GO_BUILDFLAGS=	-ldflags "-w -X github.com/${GH_ACCOUNT}/${GH_PROJECT}/internal.Version=${PORTVERSION}"
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		${DATADIR_REL}/themes/default.theme \
		${DATADIR_REL}/themes/irssi.theme \
		${DATADIR_REL}/themes/night.theme

post-patch:
	@${LN} -sf xdg_linux.go \
		${WRKSRC}/vendor/github.com/OpenPeeDeeP/xdg/xdg_${OPSYS:tl}.go

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -a ${WRKSRC}/themes ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
