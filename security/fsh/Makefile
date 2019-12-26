# Created by: sumikawa
# $FreeBSD$

PORTNAME=	fsh
PORTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://www.lysator.liu.se/fsh/ \
		http://mirror2.unixfreunde.de/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast remote command execution

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

USES=		python:2.7
GNU_CONFIGURE=	yes

INFO=	fsh

post-patch:
	${REINPLACE_CMD} -e '/^[^#]/s/FCNTL/fcntl/g' ${WRKSRC}/fshcompat.py

post-build:
	${PYTHON_CMD} -c 'import py_compile; py_compile.main()' ${WRKSRC}/*.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/*.pyc ${STAGEDIR}${PREFIX}/share/fsh

.include <bsd.port.mk>
