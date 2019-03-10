# $FreeBSD$

PORTNAME=	dsbsu
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://freeshell.de/~mk/download/

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Qt frontend to su(1)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang gl qmake qt:5 tar:tgz
USE_GL=		gl
USE_QT=		buildtools_build core gui linguisttools_build widgets

PLIST_FILES=	bin/dsbsu share/applications/dsbsu.desktop \
		${DATADIR}/dsbsu_de.qm

.include <bsd.port.mk>
