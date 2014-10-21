# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gato
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	http://gato.sourceforge.net/Download/
MASTER_SITE_SUBDIR=	gato
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Gato-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python-based toolbox to visualise algorithms on graphs

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter

WRKSRC=		${WRKDIR}/Gato

USES=		python

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's,^.*__future__.*$$,,' ${WRKSRC}/DataStructures.py
	@${GREP} -lR "^#!" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		'/^#!/s|python.*$$|python|g'

pre-build:
	@${TOUCH} ${WRKSRC}/__init__.py

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHON_SITELIBDIR} \
		-f ${WRKSRC}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHON_SITELIBDIR} \
		-f ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/Gato
.for pyfile in *.py *.pyc *.pyo
	${INSTALL_DATA} ${WRKSRC}/${pyfile} ${STAGEDIR}${PYTHON_SITELIBDIR}/Gato
.endfor
.for script in Gato Gred
	@${CHMOD} ${BINMODE} ${STAGEDIR}${PYTHON_SITELIBDIR}/Gato/${script}.py
	@${LN} -sf ${PYTHON_SITELIBDIR}/Gato/${script}.py ${STAGEDIR}${PREFIX}/bin/${script}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for egfile in *.alg *.pro *.cat
	${INSTALL_DATA} ${WRKSRC}/${egfile} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
