PORTNAME=	onlykey
PORTVERSION=	1.2.2
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dmytro@posteo.net
COMMENT=	Python command line tool for configuring and using OnlyKey

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hidapi>0:comms/py-hidapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aenum>0:devel/py-aenum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=2:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=1.4.0:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ecdsa>=0.13:security/py-ecdsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cython>=0.23.4:lang/cython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libusb1>0:devel/py-libusb1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uhid-freebsd>0:devel/py-uhid-freebsd@${PY_FLAVOR} \
		u2f-host:security/libu2f-host

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

SUB_FILES=	pkg-message

PLIST_FILES=	"@sample ${PREFIX}/etc/devd/onlykey.conf.sample" \
		"${PREFIX}/man/man1/onlykey-cli.1.gz"

NO_ARCH=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_DATA} ${FILESDIR}/onlykey.conf.sample \
		${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_MAN} ${FILESDIR}/onlykey-cli.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
