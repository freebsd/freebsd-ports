PORTNAME=	modules
DISTVERSION=	5.7.0
CATEGORIES=	sysutils tcl
MASTER_SITES=	https://github.com/envmodules/modules/releases/download/v${DISTVERSION}/

MAINTAINER=	laurent@FreeBSD.org
COMMENT=	Dynamic modification of a user environment
WWW=		https://modules.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	runtest:misc/dejagnu

USES=		gmake python:build shebangfix tar:bzip2 tcl

SHEBANG_FILES=	script/envml

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/Modules
CONFIGURE_ARGS=	--enable-versioning \
		--with-modulepath=${GNU_CONFIGURE_PREFIX}/\$$MODULE_VERSION/modulefiles:${PREFIX}/etc/modulefiles \
		--with-python="${PYTHON_CMD}" \
		--with-tclsh="${TCLSH}"

TEST_TARGET=	test

PORTSCOUT=	site:https://codeload.github.com/envmodules/modules/tar.gz/v${DISTVERSION}
SUB_FILES=	pkg-message
PLIST_SUB=	MODULES_VERSION=${DISTVERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${GNU_CONFIGURE_PREFIX}/${DISTVERSION}/lib/libtclenvmodules.so

post-stage:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/modulefiles \
		${STAGEDIR}${PREFIX}/etc/profile.d
	${RLN} ${STAGEDIR}${PREFIX}/Modules/${PORTVERSION}/init/profile.sh \
		${STAGEDIR}${PREFIX}/etc/profile.d/module.sh
	${RLN} ${STAGEDIR}${PREFIX}/Modules/${PORTVERSION}/init/profile.csh \
		${STAGEDIR}${PREFIX}/etc/profile.d/module.csh

.include <bsd.port.mk>
