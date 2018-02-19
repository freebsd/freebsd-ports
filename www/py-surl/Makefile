# Created by: Carlo Strub <c-s@c-s.li>
# $FreeBSD$

PORTNAME=	surl
PORTVERSION=	0.7.1.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://launchpadlibrarian.net/96097348/ \
		http://www.c-s.li/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	URL shortening command line application

LICENSE=	GPLv3

USES=		python:2.7 tar:bzip2
USE_PYTHON=	distutils

post-patch:
	@${REINPLACE_CMD} -e 's,share/man/man1,${PREFIX}/man/man1,g' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
