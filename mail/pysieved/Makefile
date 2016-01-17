# Created by: Denis Shaposhnikov <dsh@wizard.volgograd.ru>
# $FreeBSD$

PORTNAME=	pysieved
PORTVERSION=	1.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	mail python
MASTER_SITES=	http://ports.internal.vlink.ru/distfiles/

MAINTAINER=	dsh@wizard.volgograd.ru
COMMENT=	Python Managesieve Server

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python tar:bzip2
USE_RC_SUBR=	${PORTNAME}
NO_ARCH=	yes

PORTEXAMPLES=	pysieved.xinetd
SUB_LIST=	PORTNAME=${PORTNAME} PYTHON_CMD=${PYTHON_CMD}

PORTDOCS=	COPYING README README.Dovecot THANKS

post-patch:
	${REINPLACE_CMD} \
		's!/usr/bin/env python!${PYTHON_CMD}!' \
		${WRKSRC}/pysieved.py

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX}/lib/${PORTNAME} ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "*.py *.pyc plugins" ${STAGEDIR}${PREFIX}/lib/${PORTNAME})
	${CHMOD} ${BINMODE} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTNAME}.py
	${INSTALL_DATA} ${WRKSRC}/pysieved.ini \
		${STAGEDIR}${PREFIX}/etc/pysieved.ini.sample

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/contrib && \
		${COPYTREE_SHARE} "${PORTEXAMPLES}" ${STAGEDIR}${EXAMPLESDIR})

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
