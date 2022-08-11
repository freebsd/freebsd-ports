PORTNAME=	modules
PORTVERSION=	4.6.0
CATEGORIES=	sysutils tcl
MASTER_SITES=	https://github.com/cea-hpc/modules/releases/download/v${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic modification of a user environment

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR} \
		bash:shells/bash

USES=			gmake python:env shebangfix tar:bzip2 tcl
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/Modules
CONFIGURE_SHELL=	${LOCALBASE}/bin/bash
CONFIGURE_ARGS=		--disable-compat-version \
			--enable-versioning \
			--with-python="${PYTHON_CMD}"

PLIST_SUB=	MODULES_VERSION=${PORTVERSION}

post-extract:
	${MV} ${WRKSRC}/doc/build/modulefile.4 ${WRKSRC}/doc/build/modulefile.5

post-install:
	@${STRIP_CMD} ${STAGEDIR}${GNU_CONFIGURE_PREFIX}/${PORTVERSION}/lib/libtclenvmodules.so

.include <bsd.port.mk>
