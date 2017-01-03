# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-startup-scripts
PORTVERSION=	1.2.1
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Startup scripts that interact with Google Compute Engine VMs

BUILD_DEPENDS=	python:lang/python
RUN_DEPENDS=	python:lang/python \
		curl:ftp/curl \
		bash:shells/bash \
		flock:sysutils/flock

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	GoogleCloudPlatform
GH_PROJECT=	compute-image-packages
USE_RC_SUBR=	google-startup
WRKSRC_SUBDIR=	${PORTNAME}

SHEBANG_FILES= usr/share/google/fetch_script \
		usr/share/google/first-boot \
		usr/share/google/get_metadata_value \
		usr/share/google/onboot \
		usr/share/google/regenerate-host-keys \
		usr/share/google/run-scripts \
		usr/share/google/run-shutdown-scripts \
		usr/share/google/run-startup-scripts \
		usr/share/google/set-hostname \
		usr/share/google/boto/boot_setup.py

post-patch:
	@${RM} ${WRKSRC}/usr/share/google/safe_format_and_mount \
		${WRKSRC}/usr/share/google/virtionet-irq-affinity
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/usr/share/google/fetch_script \
		${WRKSRC}/usr/share/google/first-boot \
		${WRKSRC}/usr/share/google/onboot \
		${WRKSRC}/usr/share/google/run-shutdown-scripts \
		${WRKSRC}/usr/share/google/run-startup-scripts \
		${WRKSRC}/usr/share/google/boto/boot_setup.py
	@${RM} ${WRKSRC}/usr/share/google/*.bak \
		${WRKSRC}/usr/share/google/*.orig

do-build:
	${PYTHON_CMD} -m compileall ${WRKSRC}/usr/share/google/boto

do-install:
	cd ${WRKSRC}/usr/share ; ${COPYTREE_BIN} google ${STAGEDIR}${PREFIX}/share

.include <bsd.port.mk>
