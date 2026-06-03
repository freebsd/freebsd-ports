PORTNAME=	edfbrowser
DISTVERSION=	2.14
CATEGORIES=	misc
MASTER_SITES=	https://www.teuniz.net/${PORTNAME}/
DISTNAME=	${PORTNAME}_${DISTVERSION:S/.//}_source

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Viewer, annotator, toolbox for timeseries files EEG, EMG, ECG, etc
WWW=		https://www.teuniz.net/edfbrowser/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		desktop-file-utils gl qmake qt:6 shared-mime-info
USE_QT=		base tools:build
USE_GL=		opengl

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/edfbrowser

.include <bsd.port.mk>
