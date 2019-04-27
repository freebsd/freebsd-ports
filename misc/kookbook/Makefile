# $FreeBSD$

PORTNAME=	kookbook
DISTVERSION=	0.2.1
CATEGORIES=	misc kde
MASTER_SITES=	KDE/unstable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Recipes database with Markdown support

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/libmarkdown.a:textproc/discount

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_QT=		core declarative gui network printsupport widgets \
		qmake_build buildtools_build
USE_KDE=	ecm_build

.include <bsd.port.mk>
