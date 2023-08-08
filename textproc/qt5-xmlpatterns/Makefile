PORTNAME=	xmlpatterns
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	textproc
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt support for XPath, XQuery, XSLT and XML Schema

USES=		compiler:c++11-lang perl5 qmake:norecursive qt-dist:5,xmlpatterns
USE_PERL5=	build
USE_QT=		core declarative network buildtools:build

QT_BINARIES=	yes

.include <bsd.port.mk>
