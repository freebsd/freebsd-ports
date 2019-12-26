# Created by: Marcelo/Porks Rossi <marcelorossi@gmail.com>
# $FreeBSD$

PORTNAME=	monast
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	www net
MASTER_SITES=	SF/monast/MonAst%20for%20Asterisk%201.4_1.6/1.4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monitoring and an operator panel interface for AsteriskTM

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

USES=		python:2.7
USE_RC_SUBR=	monast

NO_BUILD=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin/python,${PYTHON_CMD},' \
			  -e 's,/etc,${PREFIX}/etc,g' \
		${WRKSRC}/pymon/monast.py

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/monast/amapi ${STAGEDIR}${PREFIX}/monast/simplejson ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/pymon/monast.py ${STAGEDIR}${PREFIX}/monast/monast.py
	${INSTALL_DATA} ${WRKSRC}/pymon/monast.conf.sample ${STAGEDIR}${PREFIX}/etc/
	${INSTALL_DATA} ${WRKSRC}/pymon/amapi/* ${STAGEDIR}${PREFIX}/monast/amapi/
	${INSTALL_DATA} ${WRKSRC}/pymon/simplejson/* ${STAGEDIR}${PREFIX}/monast/simplejson/
	${INSTALL_DATA} ${WRKSRC}/*.php ${STAGEDIR}${WWWDIR}/
.for f in css image template js
	@${MKDIR} ${STAGEDIR}${WWWDIR}/${f}
	${INSTALL_DATA} ${WRKSRC}/${f}/* ${STAGEDIR}${WWWDIR}/${f}/
.endfor
	(cd ${WRKSRC}/lib/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR}/lib)

	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d ${PYTHONPREFIX_SITELIBDIR} -f ${STAGEDIR}${PREFIX}/monast
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -d ${PYTHONPREFIX_SITELIBDIR} -f ${STAGEDIR}${PREFIX}/monast

.include <bsd.port.mk>
