# New ports collection makefile for:	py-fcgi
# Date created:		18 July 2002
# Whom:			JunSeon Oh <hollywar@mail.holywar.net>
#
# $FreeBSD$
#

PORTNAME=	fcgi
PORTVERSION=	0.1
CATEGORIES=	www python
MASTER_SITES=	http://alldunn.com/python/ \
		ftp://ftp.holywar.net/pub/FreeBSD/
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.py
EXTRACT_ONLY=	#

MAINTAINER=	hollywar@mail.holywar.net
COMMENT=	Python FastCGI interface library

USE_PYTHON=	yes
NO_WRKSUBDIR=	yes

post-extract:
	@${INSTALL_DATA} ${DISTDIR}/fcgi.py ${WRKSRC}

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${INSTALL_DATA} ${WRKSRC}/fcgi.py* ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
