PORTNAME=	decord
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	multimedia python # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Efficient video loader for deep learning
WWW=		https://github.com/olemb/mido

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libdecord.so:multimedia/decord

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	dmlc

WRKSRC_SUBDIR=	python

MAKE_ENV=	DECORD_LIBRARY_PATH=${LOCALBASE}/lib

POST_PLIST=	fix-plist

NO_ARCH=	yes

fix-plist:
	@${REINPLACE_CMD} -e "s|decord/libdecord.so||" ${TMPPLIST}

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/decord/libdecord.so
	@${RMDIR} ${STAGEDIR}${PREFIX}/decord

.include <bsd.port.mk>
