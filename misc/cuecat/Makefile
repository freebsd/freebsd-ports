# Created by: mwm@mired.org
# $FreeBSD$

PORTNAME=	cuecat
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	misc python
MASTER_SITES=	http://www.mired.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for decoding and using the output of a :Cue:Cat(TM) wand scanner

BROKEN=		unfetchable

USES=		python shebangfix

SHEBANG_FILES=	*.py
python_OLD_CMD=	/usr/opt/bin/python

WRKSRC=		${WRKDIR}/cuecat

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11
OPTIONS_SUB=	yes

X11_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter \
		${PYTHON_PKGNAMEPREFIX}Pmw>0:x11-toolkits/py-Pmw

.include <bsd.port.options.mk>

do-build:
	${PYTHON_CMD} -m compileall ${WRKSRC}
	${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
.for i in barcode cuecat
	${INSTALL_SCRIPT} ${WRKSRC}/${i}.py ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/${i}.py[co] ${STAGEDIR}${PYTHON_SITELIBDIR}
.endfor
	${LN} -sf ${PYTHON_SITELIBDIR}/cuecat.py ${STAGEDIR}${PREFIX}/bin/cuecat
	${INSTALL_MAN} ${WRKSRC}/cuecat.1 ${STAGEDIR}${PREFIX}/man/man1
.if ${PORT_OPTIONS:MX11}
	${INSTALL_SCRIPT} ${WRKSRC}/xcuecat.py ${STAGEDIR}${PREFIX}/bin/xcuecat
	${INSTALL_MAN} ${WRKSRC}/xcuecat.1 ${STAGEDIR}${PREFIX}/man/man1
.endif

.include <bsd.port.mk>
