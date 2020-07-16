# $FreeBSD$

PORTNAME=	plumed
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1
CATEGORIES=	science graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PLUgin for MolEcular Dynamics

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BROKEN_i386=	undefined reference to `__atomic_load'

BUILD_DEPENDS=	bash:shells/bash \
		xxd:editors/vim-console
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf compiler:c++11-lang gmake pkgconfig shebangfix
SHEBANG_GLOB=	*.sh
SHEBANG_FILES=	src/maketools/makecmd
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_PROJECT=	plumed2
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--enable-shared --disable-python

post-patch:
	@${REINPLACE_CMD} -e 's|#! /bin/bash|#! ${LOCALBASE}/bin/bash|' ${WRKSRC}/src/lib/Makefile

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/plumed/obj
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/plumed lib/plumed/plumed-runtime lib/libplumed.so  lib/libplumedKernel.so

.include <bsd.port.mk>
