PORTNAME=	pageedit
DISTVERSION=	2.7.6
CATEGORIES=	textproc

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	WYSIWYG visual XHTML editor
WWW=		https://github.com/Sigil-Ebook/PageEdit

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		cmake compiler:c++17-lang desktop-file-utils gl qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	Sigil-Ebook
GH_PROJECT=	PageEdit
USE_GL=		opengl
USE_QT=		base declarative positioning svg translations webchannel \
		webengine

CONFLICTS_INSTALL=	dooble

.include <bsd.port.mk>
