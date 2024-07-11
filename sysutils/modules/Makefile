PORTNAME=	modules
DISTVERSION=	5.4.0
CATEGORIES=	sysutils tcl
MASTER_SITES=	https://github.com/cea-hpc/modules/releases/download/v${PORTVERSION}/

MAINTAINER=	laurent.chardon@gmail.com
COMMENT=	Dynamic modification of a user environment
WWW=		https://modules.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR} \
		bash:shells/bash

USES=			gmake python:env shebangfix tar:bzip2 tcl
GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
GNU_CONFIGURE_PREFIX=	${PREFIX}/Modules
CONFIGURE_SHELL=	${LOCALBASE}/bin/bash
CONFIGURE_ARGS=		--enable-versioning \
			--with-python="${PYTHON_CMD}"

PLIST_SUB=	MODULES_VERSION=${PORTVERSION}

post-stage:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/profile.d
	${RLN} ${STAGEDIR}${PREFIX}/Modules/${PORTVERSION}/init/profile.sh \
		${STAGEDIR}${PREFIX}/etc/profile.d/module.sh
	${RLN} ${STAGEDIR}${PREFIX}/Modules/${PORTVERSION}/init/profile.csh \
		${STAGEDIR}${PREFIX}/etc/profile.d/module.csh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${GNU_CONFIGURE_PREFIX}/${PORTVERSION}/lib/libtclenvmodules.so

.include <bsd.port.mk>
