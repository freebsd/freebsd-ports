# New ports collection makefile for:	pysieved
# Date created:		Thu Jan 10 18:51:17 MSK 2008
# Whom:			Denis Shaposhnikov <dsh@wizard.volgograd.ru>
#
# $FreeBSD$
#

PORTNAME=	pysieved
PORTVERSION=	1.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	mail python
MASTER_SITES=	http://ports.internal.vlink.ru/distfiles/

MAINTAINER=	dsh@wizard.volgograd.ru
COMMENT=	Python Managesieve Server

USE_BZIP2=	yes
USE_PYTHON=	2.5+
USE_RC_SUBR=	${PORTNAME}

PORTEXAMPLES=	pysieved.xinetd
SUB_LIST=	PORTNAME=${PORTNAME} PYTHON_CMD=${PYTHON_CMD}

.if !defined(NOPORTDOCS)
PORTDOCS=	COPYING README README.Dovecot THANKS
.endif

post-patch:
	${REINPLACE_CMD} \
		's!/usr/bin/env python!${PYTHON_CMD}!' \
		${WRKSRC}/pysieved.py

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX}/lib/${PORTNAME} ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "*.py *.pyc plugins" ${PREFIX}/lib/${PORTNAME})
	${CHMOD} ${BINMODE} ${PREFIX}/lib/${PORTNAME}/${PORTNAME}.py
	${INSTALL_DATA} ${WRKSRC}/pysieved.ini \
		${PREFIX}/etc/pysieved.ini.sample

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/contrib && \
		${COPYTREE_SHARE} "${PORTEXAMPLES}" ${EXAMPLESDIR})
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${DOCSDIR})
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/pysieved.ini ]; then \
		${CP} -p ${PREFIX}/etc/pysieved.ini.sample ${PREFIX}/etc/pysieved.ini; \
	fi

.include <bsd.port.mk>
