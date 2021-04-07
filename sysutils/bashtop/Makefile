PORTNAME=	bashtop
DISTVERSION=	0.9.25
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Linux/OSX/FreeBSD resource monitor

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	coreutils>0:sysutils/coreutils \
		gsed:textproc/gsed \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}

USES=	python:3.5+,run

USE_GITHUB=	yes
GH_ACCOUNT=	aristocratos
GH_TAGNAME=	d2eb76e

PLIST_FILES=	bin/bashtop

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bashtop ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
