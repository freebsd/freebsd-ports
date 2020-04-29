# $FreeBSD$

PORTNAME=	netron
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.2
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	LOCAL/yuri/:js
DISTFILES=	netron-${DISTVERSION}-node_modules.tgz:js

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Visualizer for neural network, deep learning, machine learning models

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	lutzroeder
USE_PYTHON=	distutils noflavors

NO_ARCH=	yes

PLIST_SUB=	PYTHON_CPYTHON=cpython-${PYTHON_VER:S/.//}

post-extract:
	@${RLN} ${WRKDIR}/node_modules ${WRKSRC}/node_modules

#
# To update the netron-${DISTVERSION}-node_modules.tgz archive:
# 1. Comment out the DISTFILES and post-extract lines
# 2. Run 'make makesum regenerate-node_modules-distfile clean'
# 3. Upload the archive
# 4. Uncomment the lines from step #1
# 5. Run 'make makesum'
#

regenerate-node_modules-distfile: patch # requires npm installed by www/npm
	@${MAKE} clean patch && \
	cd ${WRKSRC} && \
	${RM} -r node_modules && \
	npm install -l && \
	${TAR} czf ${DISTDIR}/netron-${DISTVERSION}-node_modules.tgz node_modules && \
	${ECHO} "Please upload the file ${DISTDIR}/netron-${DISTVERSION}-node_modules.tgz"

.include <bsd.port.mk>
