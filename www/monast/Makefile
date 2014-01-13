# Created by: Marcelo/Porks Rossi <marcelorossi@gmail.com>
# $FreeBSD$

PORTNAME=	monast
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	www net
MASTER_SITES=	SF/monast/MonAst%20for%20Asterisk%201.4_1.6/1.4

MAINTAINER=	marcelorossi@gmail.com
COMMENT=	A monitoring and an operator panel interface for AsteriskTM

USE_PYTHON=	yes
USE_RC_SUBR=	monast

NO_BUILD=	YES

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/python,${PYTHON_CMD},' \
			  -e 's,/etc,${PREFIX}/etc,g' \
		${WRKSRC}/pymon/monast.py

do-install:
	@${MKDIR} ${PREFIX}/monast/amapi ${PREFIX}/monast/simplejson ${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/pymon/monast.py ${PREFIX}/monast/monast.py
	${INSTALL_DATA} ${WRKSRC}/pymon/monast.conf.sample ${PREFIX}/etc/monast.conf.default
	${INSTALL_DATA} ${WRKSRC}/pymon/amapi/* ${PREFIX}/monast/amapi/
	${INSTALL_DATA} ${WRKSRC}/pymon/simplejson/* ${PREFIX}/monast/simplejson/
	${INSTALL_DATA} ${WRKSRC}/*.php ${WWWDIR}/
.for f in css image template js
	@${MKDIR} ${WWWDIR}/${f}
	${INSTALL_DATA} ${WRKSRC}/${f}/* ${WWWDIR}/${f}/
.endfor
	(cd ${WRKSRC}/lib/ && ${COPYTREE_SHARE} \* ${WWWDIR}/lib)

post-install:
	@if [ ! -f ${PREFIX}/etc/monast.conf ]; then \
		${CP} -p ${PREFIX}/etc/monast.conf.default ${PREFIX}/etc/monast.conf ; \
	fi
	${PYTHON_CMD} -O -mcompileall ${PREFIX}/monast/
	${PYTHON_CMD} -mcompileall ${PREFIX}/monast/

.include <bsd.port.mk>
