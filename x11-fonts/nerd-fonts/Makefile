# $FreeBSD$

PORTNAME=	nerd-fonts
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	x11-fonts

MAINTAINER=	gregf@hugops.pw
COMMENT=	Developer-targeted fonts with a high number of glyphs

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
	@${RMDIR} ${STAGEDIR}${FONTSDIR}/ProFont/ProFontWinTweaked/complete \
		${STAGEDIR}${FONTSDIR}/ProFont/ProFontWinTweaked \
		${STAGEDIR}${FONTSDIR}/ProFont/profont-x11 \
		${STAGEDIR}${FONTSDIR}/Terminus/BDF \
		${STAGEDIR}${FONTSDIR}/Terminus/PCF \
		${STAGEDIR}${FONTSDIR}/Terminus/PSF \

.include <bsd.port.mk>
