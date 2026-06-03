PORTNAME=	kookbook
DISTVERSION=	0.3.0
CATEGORIES=	misc kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Recipes database with Markdown support
WWW=		https://pusling.com/blog/?p=499

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++17-lang kde:6 qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		base declarative

post-patch:
	${REINPLACE_CMD} -e 's,^Name.*Kookbook,& Touch,' \
		${WRKSRC}/src/touch/org.kde.kookbooktouch.desktop

.include <bsd.port.mk>
