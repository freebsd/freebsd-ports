# New ports collection makefile for:	py2html
# Date created:				15 Nov 2000
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	py2html
PORTVERSION=	0.6
CATEGORIES=	textproc www python
MASTER_SITES=	http://dist.freebsd-kr.org/pub/FreeBSD/ports/distfiles/ \
		ftp://ftp2.python.or.kr/pub/FreeBSD/ports/distfiles/

MAINTAINER=	perky@fallin.lv

USE_PYTHON=	yes
PLIST_SUB+=	PYTHON_LIBPATH=${PYTHON_LIBPATH:S/^${LOCALBASE}//g}lib \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/PyFontify.py* ${PYTHON_SITELIBDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/py2html.py ${LOCALBASE}/bin/py2html
	${INSTALL_SCRIPT} ${WRKSRC}/py2html.pyc ${LOCALBASE}/bin/

.include <bsd.port.mk>
