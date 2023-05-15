PORTNAME=	adjuster
DISTVERSIONPREFIX=	v
DISTVERSION=	3.23-23
DISTVERSIONSUFFIX=	-g7c06b0f
CATEGORIES=	www

MAINTAINER=	ssb22@cam.ac.uk
COMMENT=	Apply custom processing to Web pages
WWW=		http://ssb22.user.srcf.net/adjuster/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tornado>0:www/py-tornado@${PY_FLAVOR}

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	ssb22
SHEBANG_FILES=	*.py

NO_ARCH=	yes

PLIST_FILES=	bin/adjuster \
		bin/annogen \
		bin/termlayout

.include <bsd.port.mk>
