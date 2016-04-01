# Created by: Hizbulin Ildar <hizel@vyborg.ru>
# $FreeBSD$

PORTNAME=	supervisor
PORTVERSION=	3.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hizel@vyborg.ru
COMMENT=	System to monitor and control a number of processes on UNIX-like OS

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meld3>=0.6.5:www/py-meld3
TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Install mock for running unit tests

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock
.endif

PORTDOCS=	*.txt *.rst

USES=		python:2
USE_PYTHON=	distutils autoplist
PIDDIR?=	/var/run/supervisor

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		PIDDIR=${PIDDIR}
PLIST_SUB=	PIDDIR=${PIDDIR}
USE_RC_SUBR=	supervisord

post-patch:
	@${REINPLACE_CMD} -e 's!%%PREFIX%%!${PREFIX}!' ${WRKSRC}/supervisor/options.py

post-install:
	${INSTALL_DATA} ${FILESDIR}/supervisord.conf.sample ${STAGEDIR}${PREFIX}/etc
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
