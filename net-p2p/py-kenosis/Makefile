# New ports collection makefile for:	kenosis
# Date created:		Thu Jan 13 01:15:19 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kenosis
PORTVERSION=	0.95
CATEGORIES=	net-p2p python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A fully-distributed p2p RPC system built on top of XMLRPC

RUN_DEPENDS=	\
		${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/xmlrpclib.py:${PORTSDIR}/net/py-xmlrpclib

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYSETUP=	${PORTNAME}_setup.py

post-extract:
# Avoid name collision and move ds inside kenosis package
# it is only used by kenosis anyway
	@${MV} ${WRKSRC}/ds ${WRKSRC}/${PORTNAME}
# Contributed by Eric Ries <eric.ries@aya.yale.edu> - kenosis developer
# Queue.py changed API from python 2.3 to 2.4
# use Queue.py from python 2.3 while kenosis developers fix this
	@${CP} ${FILESDIR}/python2.3-Queue.py \
		${WRKSRC}/${PORTNAME}/Queue.py

post-patch:
# ds was moved inside kenosis package
# use local copy of Queue
# point at correct python
	@${FIND} ${WRKSRC} -type f -print0 \
		| ${XARGS} -0 -n 5 -x \
		${REINPLACE_CMD} -E \
		-e 's|from[[:space:]]+ds|from ${PORTNAME}.ds|' \
		-e 's|import[[:space:]]+Queue|from ${PORTNAME} import Queue|' \
		-e 's|/usr/bin/python|${PYTHON_CMD}|' \
		-e 's|/usr/bin/env[[:space:]]+python|${PYTHON_CMD}|'
# remove all .bak files
	@${FIND} ${WRKSRC} -name "*.bak" -type f -print0 \
		| ${XARGS} -0 -n 5 -x \
		${RM} -f
# Contributed by Eric Ries <eric.ries@aya.yale.edu> - kenosis developer
# set default time out to 20
	@${REINPLACE_CMD} -E \
		-e 's|(socket.setdefaulttimeout)\([[:digit:]]+\)|\1(20)|' \
		${WRKSRC}/${PORTNAME}/node.py

post-install:
# fix post-install permissions
	@${FIND} ${PYTHON_SITELIBDIR} -type f -print0 \
		| ${XARGS} -0 -n 5 -x \
		${CHMOD} ${SHAREMODE}

.include <bsd.port.mk>
