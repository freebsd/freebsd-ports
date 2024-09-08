PORTNAME=	hexyl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.0
PORTREVISION=	6
CATEGORIES=	sysutils

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Command-line hex viewer
WWW=		https://github.com/sharkdp/hexyl

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	sharkdp

PLIST_FILES=	bin/hexyl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/hexyl

.include <bsd.port.mk>
