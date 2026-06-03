PORTNAME=	ictree
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/NikitaIvanovV/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Like tree(1) but interactive
WWW=		https://nikitaivanovv.github.io/ictree/ \
		https://github.com/NikitaIvanovV/ictree/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/ictree \
		share/man/man1/ictree.1.gz

.include <bsd.port.mk>
