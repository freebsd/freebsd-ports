PORTNAME=	ai-ml-env
PORTVERSION=	1.0.0
CATEGORIES=	science linux
MASTER_SITES=	https://arrowd.name/
PKGNAMEPREFIX=	linux-
DISTFILES=	miniconda3.tar.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	voxnod@gmail.com
COMMENT=	Linux Python environment for running Stable Diffusion models and PyTorch CUDA examples

ONLY_FOR_ARCHS=	amd64

LICENSE=	MULTI
LICENSE_NAME=	Multiple licenses
LICENSE_TEXT=	The package contains multiple packages with different licenses
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

FETCH_DEPENDS=	linux_base-rl9>=9.2:emulators/linux_base-rl9
BUILD_DEPENDS=	linux-rl9-devtools>=0:devel/linux-rl9-devtools
RUN_DEPENDS=	linux-nvidia-libs>=0:x11/linux-nvidia-libs \
		linux-rl9-python${PYTHON_SUFFIX}>=0:lang/linux-rl9-python3 \
		nvidia-driver>=0:x11/nvidia-driver

USES=		linux:rl9
USE_LINUX_PREFIX=	yes
USE_GITHUB=	nodefault
GH_ACCOUNT=	pytorch:examples
GH_PROJECT=	examples:examples
GH_TAGNAME=	5dfeb46902baf444010f2f54bcf4dfbea109ae4d:examples

WRKSRC=		${WRKSRC_examples}

SUB_FILES=	ai-ml-env-bash \
		ai-ml-env-python
SUB_LIST=	LOCALBASE=${LOCALBASE} \
		LINUXBASE=${LINUXBASE}

PLIST_SUB+=     PYTHON_SUFFIX=${PYTHON_SUFFIX} \
		PYTHON_VER=${PYTHON_VER}

CONDA_VERSION=	py39_25.1.1-2
CONDA_SCRIPT=	Miniconda3-${CONDA_VERSION}-Linux-x86_64.sh
PYTHON_SUFFIX=	39
PYTHON_VER=	3.9
DATA_DIR=	${LOCALBASE}/share/${PORTNAME}

create-distfile:
	${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && \
		fetch -a -v https://repo.anaconda.com/miniconda/${CONDA_SCRIPT}
	@if [ ! -d "${DISTDIR}/${DIST_SUBDIR}/miniconda3/envs/pytorch" ]; then \
		${ECHO_MSG} "Miniconda environment 'pytorch' not found. Setting up..."; \
		${SETENV} HOME=${DISTDIR}/${DIST_SUBDIR} ${SH} ${DISTDIR}/${DIST_SUBDIR}/${CONDA_SCRIPT} -b -s; \
		${DISTDIR}/${DIST_SUBDIR}/miniconda3/bin/conda create --name pytorch python=${PYTHON_VER} -y; \
		${LINUXBASE}/bin/bash -c "source ${DISTDIR}/${DIST_SUBDIR}/miniconda3/etc/profile.d/conda.sh && \
			conda activate pytorch && \
			pip install -r ${FILESDIR}/requirements.txt"; \
	fi
	cd ${DISTDIR}/${DIST_SUBDIR} && \
		tar -czf miniconda3.tar.gz miniconda3
	${MAKE} makesum

do-build:
	/compat/linux/bin/cc --sysroot=/compat/linux -m64 -std=c99 -Wall -ldl -fPIC -shared -o ${WRKDIR}/dummy-uvm.so ${FILESDIR}/uvm_ioctl_override.c

do-install:
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	# Install Linux Python packages
	${MKDIR} ${STAGEDIR}${PREFIX}/usr/bin
	${FIND} ${WRKDIR}/miniconda3/envs/pytorch/bin -type f -exec ${CP} {} ${STAGEDIR}${PREFIX}/usr/bin \;
	${MKDIR} ${STAGEDIR}${PREFIX}/usr/lib/python${PYTHON_VER}
	${CP} -r ${WRKDIR}/miniconda3/envs/pytorch/lib/python${PYTHON_VER}/site-packages ${STAGEDIR}${PREFIX}/usr/lib/python${PYTHON_VER}
	for item in `cat ${FILESDIR}/redundant-items.txt`; do \
		${RM} -r ${STAGEDIR}${PREFIX}/usr/$$item; \
	done
	${FIND} ${STAGEDIR}${PREFIX}/usr/bin -type f -exec ${REINPLACE_CMD} -i '' 's|^#!.*/miniconda3/envs/pytorch/bin/python|#!/bin/python3|' {} +
	# Install Shkhln's lib
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_LIB} ${WRKDIR}/dummy-uvm.so ${STAGEDIR}${DATADIR}
	# Install Pytorch examples
	${MKDIR} ${STAGEDIR}${DATA_DIR}/pytorch-examples
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATA_DIR}/pytorch-examples
	${RM} -r ${STAGEDIR}${DATA_DIR}/pytorch-examples/.github
	${INSTALL_SCRIPT} ${WRKSRC}/run_python_examples.sh ${STAGEDIR}${DATA_DIR}/pytorch-examples
	# Install Stable Diffusion sample
	${INSTALL_DATA} ${FILESDIR}/stable-diffusion-sample.py ${STAGEDIR}${DATA_DIR}
	# Install demonstration scripts
	${MKDIR} ${STAGEDIR}${LOCALBASE}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/ai-ml-env-bash ${STAGEDIR}${LOCALBASE}/bin/ai-ml-env-bash
	${INSTALL_SCRIPT} ${WRKDIR}/ai-ml-env-python ${STAGEDIR}${LOCALBASE}/bin/ai-ml-env-python

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/usr/lib/python${PYTHON_VER} -type f | sed -e 's|${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${DATA_DIR}/pytorch-examples -type f | sed -e 's|${STAGEDIR}||' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${DATA_DIR} -type d | sed -e 's|${STAGEDIR}|@dir |' >> ${TMPPLIST}

.include <bsd.port.mk>
