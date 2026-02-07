PORTNAME=		adjuster
DISTVERSIONPREFIX=	v
DISTVERSION=		3.246
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

PLIST_FILES=	bin/adjuster         \
		bin/annogen                  \
		bin/termlayout               \
		share/man/man1/adjuster.1.gz \
		share/man/man1/annogen.1.gz  \
		share/man/man1/termlayout.1.gz

.include <bsd.port.mk>
