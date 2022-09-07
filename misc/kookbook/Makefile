PORTNAME=	kookbook
DISTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	misc kde
MASTER_SITES=	KDE/unstable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Recipes database with Markdown support
WWW=		https://pusling.com/blog/?p=499

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmarkdown.so:textproc/discount

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	ecm_build
USE_QT=		core declarative gui network printsupport widgets \
		qmake_build buildtools_build testlib_build

.include <bsd.port.mk>
