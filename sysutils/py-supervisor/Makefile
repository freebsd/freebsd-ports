# Created by: Hizbulin Ildar <hizel@vyborg.ru>
# $FreeBSD$

PORTNAME=	supervisor
PORTVERSION=	3.0
PORTEPOCH=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hizel@vyborg.ru
COMMENT=	System to monitor and control a number of processes on UNIX-like OS

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meld3>=0.6.5:${PORTSDIR}/www/py-meld3
TEST_DEPENDS:=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Install mock for running unit tests
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock
.endif

PORTDOCS=	*.txt *.rst

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
PIDDIR?=	/var/run/supervisor

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		PIDDIR=${PIDDIR}
PLIST_SUB=	PIDDIR=${PIDDIR}
USE_RC_SUBR=	supervisord

post-patch:
	@${REINPLACE_CMD} -e 's!%%PREFIX%%!${PREFIX}!' ${WRKSRC}/supervisor/options.py

post-install:
	[ -d ${PIDDIR} ] || ${MKDIR} ${PIDDIR}
	${INSTALL_DATA} ${FILESDIR}/supervisord.conf.sample ${PREFIX}/etc
	[ -f ${PREFIX}/etc/supervisord.conf ] || ${CP} -p ${PREFIX}/etc/supervisord.conf.sample ${PREFIX}/etc/supervisord.conf
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
