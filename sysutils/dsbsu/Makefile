PORTNAME=	dsbsu
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Qt frontend to su(1)
WWW=		https://github.com/mrclksr/DSBSu

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gl qmake qt:5 tar:tgz xorg
USE_GL=		gl
USE_QT=		buildtools:build core gui linguisttools:build widgets

USE_GITHUB=	yes
GH_ACCOUNT=	mrclksr
GH_PROJECT=	DSBSu

post-patch:
	@${REINPLACE_CMD} -e 's|man/man|share/man/man|' ${WRKSRC}/dsbsu.pro

.include <bsd.port.mk>
