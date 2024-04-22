PORTNAME=	clone
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	cyclaero@gmail.com
COMMENT=	File tree cloning tool
WWW=		https://cyclaero.github.io/clone/

LICENSE=	BSD2CLAUSE

USES=		compiler:c11
USE_GITHUB=	yes
GH_ACCOUNT=	cyclaero

PLIST_FILES=	bin/clone \
		share/man/man1/clone.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/clone

.include <bsd.port.mk>
