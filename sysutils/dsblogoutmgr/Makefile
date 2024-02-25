PORTNAME=	dsblogoutmgr
PORTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://freeshell.de/~mk/download/

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Graphical logout manager
WWW=		https://freeshell.de/~mk/projects/dsblogoutmgr.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gl qmake qt:5 tar:tgz

USE_GL=		gl
USE_QT=		buildtools:build core gui linguisttools:build widgets

OPTIONS_DEFINE=	METALOCK

METALOCK_DESC=	Use metalock for locking the screen

METALOCK_RUN_DEPENDS=	metalock:x11/metalock

post-patch:
	@${REINPLACE_CMD} -e 's|man/man|share/man/man|' ${WRKSRC}/dsblogoutmgr.pro

.include <bsd.port.mk>
