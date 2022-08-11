PORTNAME=	libtree
PORTVERSION=	3.1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Show library info in a tree form

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	haampie

PLIST_FILES=	bin/libtree \
		share/man/man1/libtree.1.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/libtree

.include <bsd.port.mk>
