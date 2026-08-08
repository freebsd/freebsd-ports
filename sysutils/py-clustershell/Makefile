PORTNAME=	clustershell
DISTVERSION=	1.10.1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rikka.goering@outlook.de
COMMENT=	Python framework for efficient cluster administration (NodeSet, clush)
WWW=		https://clustershell.github.io/clustershell/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPLv2.1

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	bash:shells/bash

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	@cd ${TEST_WRKSRC} && \
		${SETENV} ${TEST_ENV} \
		PYTHONPATH="${WRKSRC}/lib" \
		${PYTHON_CMD} -m unittest -v \
		tests.CLICompletionTest \
		tests.CLIConfigTest \
		tests.CLINodesetTest \
		tests.CLIOptionParserTest \
		tests.DefaultsTest \
		tests.EngineErrorTest \
		tests.MisusageTest \
		tests.MsgTreeTest \
		tests.NodeSetGroupTest \
		tests.NodeSetTest \
		tests.RangeSetNDTest \
		tests.RangeSetTest \
		tests.StreamWorkerTest \
		tests.TaskEventTest \
		tests.TaskLocalTest \
		tests.TaskMsgTreeTest \
		tests.TaskPortTest \
		tests.TaskRLimitsTest \
		tests.TaskThreadJoinTest \
		tests.TaskThreadSuspendTest \
		tests.TaskTimeoutTest \
		tests.TreeGatewayTest \
		tests.TreeTaskTest \
		tests.TreeTopologyTest \
		tests.WorkerExecTest

.include <bsd.port.mk>
