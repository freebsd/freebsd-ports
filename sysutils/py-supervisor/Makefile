# New ports collection makefile for:	supervisor
# Date created:		30 Dec, 2009
# Whom:			Hizbulin Ildar <hizel@vyborg.ru>
#
# $FreeBSD$
#

PORTNAME=	supervisor
PORTVERSION=	3.0a9
CATEGORIES=	sysutils python
MASTER_SITES=	http://dist.supervisord.org/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hizel@vyborg.ru
COMMENT=	System to monitor and control a number of processes on UNIX-like OS

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}elementtree>=1.2.6:${PORTSDIR}/devel/py-elementtree \
		${PYTHON_PKGNAMEPREFIX}meld3>=0.6.4:${PORTSDIR}/www/py-meld3 \
		${PYTHON_PKGNAMEPREFIX}cElementTree>=1.0.5:${PORTSDIR}/devel/py-celementtree

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install
PIDDIR?=	/var/run/supervisor

SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		PIDDIR=${PIDDIR}
PLIST_SUB=	PIDDIR=${PIDDIR}
USE_RC_SUBR=	supervisord

post-patch:
	${REINPLACE_CMD} -e 's!%%PREFIX%%!${PREFIX}!' ${WRKSRC}/src/supervisor/options.py

post-install:
	[ -d ${PIDDIR} ] || ${MKDIR} ${PIDDIR}
	${INSTALL_DATA} ${FILESDIR}/supervisord.conf.sample ${PREFIX}/etc
	[ -f ${PREFIX}/etc/supervisord.conf ] || ${CP} -p ${PREFIX}/etc/supervisord.conf.sample ${PREFIX}/etc/supervisord.conf

.include <bsd.port.mk>
