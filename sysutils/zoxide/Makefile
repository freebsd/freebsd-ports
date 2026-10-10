PORTNAME=	zoxide
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	sysutils

MAINTAINER=	andoriyu@gmail.com
COMMENT=	Fast cd alternative that learns your habits
WWW=		https://github.com/ajeetdsouza/zoxide

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ajeetdsouza

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
