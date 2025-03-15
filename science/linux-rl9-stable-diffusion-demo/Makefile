PORTNAME=	stable-diffusion-demo
PORTVERSION=	1.0.0
CATEGORIES=	science linux
PKGNAMEPREFIX=	linux-rl9-
DISTFILES=

MAINTAINER=	voxnod@gmail.com
COMMENT=	Stable Diffusion demonstation script

BUILD_DEPENDS=	linux-rl9-devtools>=0:devel/linux-rl9-devtools
RUN_DEPENDS=	linux-nvidia-libs>=0:x11/linux-nvidia-libs \
		linux-rl9-stable-diffusion-environment>=0:science/linux-rl9-stable-diffusion-environment \
		nvidia-driver>=0:x11/nvidia-driver

SUB_FILES=	${PORTNAME}

do-build:
	/compat/linux/bin/cc --sysroot=/compat/linux -m64 -std=c99 -Wall -ldl -fPIC -shared -o ${WRKDIR}/dummy-uvm.so ${FILESDIR}/uvm_ioctl_override.c

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_LIB} ${WRKDIR}/dummy-uvm.so ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${FILESDIR}/stable-diffusion-sample.py ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
