# Created by: JunSeon Oh <hollywar@mail.holywar.net>
# $FreeBSD$

PORTNAME=	fcgi
PORTVERSION=	0.1
CATEGORIES=	www python
MASTER_SITES=	http://alldunn.com/python/ \
		ftp://ftp.holywar.net/pub/FreeBSD/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.py
EXTRACT_ONLY=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python FastCGI interface library

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

USES=		python:2.7
NO_WRKSUBDIR=	yes

post-extract:
	@${INSTALL_DATA} ${DISTDIR}/fcgi.py ${WRKSRC}

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${WRKSRC}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/fcgi.py* ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
