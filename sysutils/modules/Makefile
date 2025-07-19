PORTNAME=	modules
DISTVERSION=	5.5.0
CATEGORIES=	sysutils tcl
MASTER_SITES=	https://github.com/cea-hpc/modules/releases/download/v${DISTVERSION}/

MAINTAINER=	laurent.chardon@gmail.com
COMMENT=	Dynamic modification of a user environment
WWW=		https://modules.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR} \
		bash:shells/bash
TEST_DEPENDS=	runtest:misc/dejagnu

USES=		gmake python:env shebangfix tar:bzip2 tcl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/Modules
CONFIGURE_ARGS=	--enable-versioning \
		--with-python="${PYTHON_CMD}"

TEST_TARGET=	test

PLIST_SUB=	MODULES_VERSION=${DISTVERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${GNU_CONFIGURE_PREFIX}/${DISTVERSION}/lib/libtclenvmodules.so

post-stage:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/profile.d
	${RLN} ${STAGEDIR}${PREFIX}/Modules/${PORTVERSION}/init/profile.sh \
		${STAGEDIR}${PREFIX}/etc/profile.d/module.sh
	${RLN} ${STAGEDIR}${PREFIX}/Modules/${PORTVERSION}/init/profile.csh \
		${STAGEDIR}${PREFIX}/etc/profile.d/module.csh

.include <bsd.port.mk>
