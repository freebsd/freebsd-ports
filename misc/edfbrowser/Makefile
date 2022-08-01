PORTNAME=	edfbrowser
DISTVERSION=	1.95
CATEGORIES=	misc
MASTER_SITES=	https://www.teuniz.net/${PORTNAME}/
DISTNAME=	${PORTNAME}_${DISTVERSION:S/.//}_source

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Viewer, annotator, toolbox for timeseries files EEG, EMG, ECG, etc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		desktop-file-utils gl qmake qt:5 shared-mime-info
USE_QT=		core gui network printsupport widgets buildtools_build
USE_GL=		gl

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/edfbrowser

.include <bsd.port.mk>
