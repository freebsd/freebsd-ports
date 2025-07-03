PORTNAME=	navi
DISTVERSIONPREFIX=	v
DISTVERSION=	2.24.0
PORTREVISION=	4
CATEGORIES=	misc

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Interactive cheatsheet tool for the command-line
WWW=		https://github.com/denisidoro/navi

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	fzf:textproc/fzf

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	denisidoro

PLIST_FILES=	bin/navi

.include <bsd.port.mk>
