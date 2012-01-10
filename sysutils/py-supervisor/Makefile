# New ports collection makefile for:	supervisor
# Date created:		30 Dec, 2009
# Whom:			Hizbulin Ildar <hizel@vyborg.ru>
#
# $FreeBSD$
#

PORTNAME=	supervisor
PORTVERSION=	3.0a12
CATEGORIES=	sysutils python
MASTER_SITES=	http://dist.supervisord.org/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hizel@vyborg.ru
COMMENT=	System to monitor and control a number of processes on UNIX-like OS

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meld3>=0.6.4:${PORTSDIR}/www/py-meld3

PORTDOCS=	*.txt *.rst

USE_PYTHON=	2.5-2.7
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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
