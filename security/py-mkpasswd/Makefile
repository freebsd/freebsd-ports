PORTNAME=	mkpasswd
DISTVERSIONPREFIX= v
PORTVERSION=	2.1
CATEGORIES=	security python

MAINTAINER=	rbranco@suse.de
COMMENT=	Overfeatured front end to crypt(3)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ricardobranco777
GH_PROJECT=	mkpasswd

USES=		python
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argon2-cffi>=21.1:security/py-argon2-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=1.7.4:security/py-passlib@${PY_FLAVOR}

NO_ARCH=	yes

PLIST_FILES=	bin/mkpasswd

# Fix she-bang
post-patch:
	${REINPLACE_CMD} -e '1s|^#!.*|#!${PYTHON_CMD}|' ${WRKSRC}/mkpasswd

do-build:
	true

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mkpasswd ${STAGEDIR}${PREFIX}/bin/mkpasswd

.include <bsd.port.mk>
