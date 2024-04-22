PORTNAME=	nerd-fonts
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.1
CATEGORIES=	x11-fonts

MAINTAINER=	gregf@hugops.pw
COMMENT=	Developer-targeted fonts with a high number of glyphs
WWW=		https://nerdfonts.com/

LICENSE=	MIT

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	ryanoasis

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC}/patched-fonts && \
	${COPYTREE_SHARE} . ${STAGEDIR}${FONTSDIR} "! -name *Windows* -and ! \
	-name *Awesome* -and ! -name *Pomicons* -and ! -name *Octicons* \
	-and ! -name *.md -and ! -name *Linux*")

.include <bsd.port.mk>
