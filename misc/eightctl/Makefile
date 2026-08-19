PORTNAME=	eightctl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
PORTREVISION=	2
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Control your sleep from the terminal
WWW=		https://github.com/steipete/eightctl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules

GO_PKGNAME=	github.com/steipete/eightctl

USE_GITHUB=	yes
GH_ACCOUNT=	steipete

GO_MODULE=	github.com/steipete/eightctl
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

xpost-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/ansi
	@${RLN} ${WRKSRC_charmbracelet_x_ansi}/ansi ${WRKSRC}/vendor/github.com/charmbracelet/x/ansi
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/cellbuf
	@${RLN} ${WRKSRC_charmbracelet_x_cellbuf}/cellbuf ${WRKSRC}/vendor/github.com/charmbracelet/x/cellbuf

.include <bsd.port.mk>
