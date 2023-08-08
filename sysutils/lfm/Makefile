PORTNAME=	lfm
PORTVERSION=	3.1
CATEGORIES=	sysutils
MASTER_SITES=	https://inigo.katxi.org/devel/lfm/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Last File Manager, a powerful file manager for the UNIX console
WWW=		https://inigo.katxi.org/devel/lfm/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python
USE_PYTHON=	autoplist distutils noflavors

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e '/print(__doc__)/d' ${WRKSRC}/setup.py

.include <bsd.port.mk>
