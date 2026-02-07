PORTNAME=	qt5ct
DISTVERSION=	1.9
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 configuration tool
WWW=		https://sourceforge.net/projects/qt5ct/

LICENSE=	BSD2CLAUSE

USES=		cmake compiler:c++11-lang gl qt:5 tar:bz2 xorg
USE_QT=		concurrent core dbus gui paths widgets \
		buildtools:build linguisttools:build qmake:build \
		svg:run
USE_GL=		gl
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
