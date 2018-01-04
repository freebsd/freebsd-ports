# Created by: ijliao
# $FreeBSD$

PORTNAME=	lfm
PORTVERSION=	3.1
CATEGORIES=	sysutils
MASTER_SITES=	https://inigo.katxi.org/devel/lfm/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Last File Manager, a powerful file manager for the UNIX console

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils noflavors
USES=		python:3.4+

PLIST_FILES=	man/man1/lfm.1.gz

post-patch:
	@${REINPLACE_CMD} -e '/print(__doc__)/d' ${WRKSRC}/setup.py

post-install:
	${INSTALL_MAN} ${WRKSRC}/lfm.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
