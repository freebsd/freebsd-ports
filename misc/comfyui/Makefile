PORTNAME=	comfyui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.2
CATEGORIES=	misc python # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Powerful and modular stable diffusion GUI with graph/nodes interface
WWW=		https://www.comfy.org/ \
		https://github.com/Comfy-Org/ComfyUI

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.11.8:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}alembic>0:databases/py-alembic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}av>=14.2.0:multimedia/py-av@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blake3>0:security/py-blake3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}comfy-aimdo>=0.2.10:misc/py-comfy-aimdo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}comfy-kitchen>=0.2.8:misc/py-comfy-kitchen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}comfyui-embedded-docs>=0.4.3:misc/py-comfyui-embedded-docs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}comfyui-frontend-package>=1.41.20:misc/py-comfyui-frontend-package@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}comfyui-workflow-templates>=0.9.21:misc/py-comfyui-workflow-templates@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}einops>0:misc/py-einops@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}glfw>0:graphics/py-glfw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kornia>=0.7.1:graphics/py-kornia@${PY_FLAVOR} \
		${PYNUMPY} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.0:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}safetensors>=0.4.2:misc/py-safetensors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentencepiece>0:textproc/py-sentencepiece@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simpleeval>0:devel/py-simpleeval@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spandrel>0:misc/py-spandrel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>0:databases/py-sqlalchemy20@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tokenizers>=0.13.3:textproc/py-tokenizers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchaudio>0:audio/py-torchaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchsde>0:math/py-torchsde@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchvision>0:misc/py-torchvision@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=4.50.3:misc/py-transformers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yarl>=1.18.0:www/py-yarl@${PY_FLAVOR} \

USES=		python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	Comfy-Org
GH_PROJECT=	ComfyUI

SHEBANG_FILES=	*.py

NO_ARCH=	yes
NO_BUILD=	yes

COMFYUI_DIR=	${PREFIX}/share/comfyui

# comfyui needs to write into some subfolders of its installation directory, so we set the writable dir to /var/db/comfyui and create symlinks to there
WRITABLE_DIR=	/var/db/${PORTNAME}

do-install:
	# copy all files to ${COMFYUI_DIR}
	${MKDIR} ${STAGEDIR}${COMFYUI_DIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${COMFYUI_DIR}
	# create the comfyui script
	( \
		${ECHO} '#!/bin/sh' && \
		${ECHO} ${PYTHON_CMD} ${COMFYUI_DIR}/main.py --disable-dynamic-vram --cpu '"$$@"' \
	) > ${STAGEDIR}${PREFIX}/bin/comfyui
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/comfyui
	# remove unnecessary files
	${RM} -r ${STAGEDIR}${COMFYUI_DIR}/.git*
	${RM} -r ${STAGEDIR}${COMFYUI_DIR}/.ci
	${RM} -r ${STAGEDIR}${COMFYUI_DIR}/.coderabbit.yaml
	# create writable symlinks
	${MKDIR} ${STAGEDIR}${WRITABLE_DIR}
	${MKDIR} ${STAGEDIR}${WRITABLE_DIR}/user
	${MKDIR} ${STAGEDIR}${WRITABLE_DIR}/user/default
	${MKDIR} ${STAGEDIR}${WRITABLE_DIR}/temp
	${RLN} -s ${STAGEDIR}${WRITABLE_DIR}/user ${STAGEDIR}${COMFYUI_DIR}/user
	${RLN} -s ${STAGEDIR}${WRITABLE_DIR}/temp ${STAGEDIR}${COMFYUI_DIR}/temp
.for dir in audio_encoders checkpoints clip clip_vision controlnet diffusers diffusion_models embeddings gligen hypernetworks \
	    latent_upscale_models loras model_patches photomaker style_models text_encoders unet upscale_models vae vae_approx
	${RM} -r ${STAGEDIR}${COMFYUI_DIR}/models/${dir}
	${MKDIR} ${STAGEDIR}${WRITABLE_DIR}/models/${dir}
	${RLN} -s ${STAGEDIR}${WRITABLE_DIR}/models/${dir} ${STAGEDIR}${COMFYUI_DIR}/models/${dir}
.endfor
	# move installed files to the writable location
	${MV} ${STAGEDIR}${COMFYUI_DIR}/input ${STAGEDIR}${WRITABLE_DIR}/input
	${RLN} -s ${STAGEDIR}${WRITABLE_DIR}/input ${STAGEDIR}${COMFYUI_DIR}/input
	${MKDIR} ${STAGEDIR}${WRITABLE_DIR}/output
	${RM} -r ${STAGEDIR}${COMFYUI_DIR}/output
	${RLN} -s ${STAGEDIR}${WRITABLE_DIR}/output ${STAGEDIR}${COMFYUI_DIR}/output

.include <bsd.port.mk>
