# Created by: mwm@mired.org
# $FreeBSD$

PORTNAME=	cuecat
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	misc python
MASTER_SITES=	http://www.mired.org/downloads/

MAINTAINER=	mwm@mired.org
COMMENT=	Tools for decoding and using the output of a :Cue:Cat(TM) wand scanner

.if !defined(WITHOUT_X11)
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/Pmw/__init__.py:${PORTSDIR}/x11-toolkits/py-Pmw
.endif

NO_BUILD=	yes
MAN1=		cuecat.1
.if !defined(WITHOUT_X11)
MAN1+=		xcuecat.1
.endif
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/cuecat

NO_STAGE=	yes
pre-install:
	@${MV} ${WRKSRC}/cuecat.py ${WRKSRC}/cuecat.py-orig
	@${SED} 's;/usr/opt/bin/python;${PYTHON_CMD};' ${WRKSRC}/cuecat.py-orig >${WRKSRC}/cuecat.py
	@${MV} ${WRKSRC}/barcode.py ${WRKSRC}/barcode.py-orig
	@${SED} 's;/usr/opt/bin/python;${PYTHON_CMD};' ${WRKSRC}/barcode.py-orig >${WRKSRC}/barcode.py
.if !defined(WITHOUT_X11)
	@${MV} ${WRKSRC}/xcuecat.py ${WRKSRC}/xcuecat.py-orig
	@${SED} 's;/usr/opt/bin/python;${PYTHON_CMD};' ${WRKSRC}/xcuecat.py-orig >${WRKSRC}/xcuecat.py
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cuecat.py ${PYTHON_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/barcode.py ${PYTHON_SITELIBDIR}
	${PYTHON_CMD} -O -c "import barcode, cuecat"
	${LN} -sf ${PYTHON_SITELIBDIR}/cuecat.py ${PREFIX}/bin/cuecat
	${INSTALL_MAN} ${WRKSRC}/cuecat.1 ${PREFIX}/man/man1
.if !defined(WITHOUT_X11)
	${INSTALL_SCRIPT} ${WRKSRC}/xcuecat.py ${PREFIX}/bin/xcuecat
	${INSTALL_MAN} ${WRKSRC}/xcuecat.1 ${PREFIX}/man/man1
.endif

.if defined(WITHOUT_X11)
post-install:
	$(MV) ${TMPPLIST} ${TMPPLIST}.orig
	${GREP} -v xcuecat ${TMPPLIST}.orig > ${TMPPLIST}
.endif

.include <bsd.port.mk>
