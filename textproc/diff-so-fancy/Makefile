PORTNAME=	diff-so-fancy
PORTVERSION=	1.4.4
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fancier diff output formatter
WWW=		https://github.com/so-fancy/diff-so-fancy/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		perl5 shebangfix
USE_GITHUB=	yes
USE_PERL5=	run

GH_ACCOUNT=	so-fancy
NO_ARCH=	yes
NO_BUILD=	yes
SHEBANG_FILES=	${WRKSRC}/diff-so-fancy
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/diff-so-fancy ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/DiffHighlight.pm \
		${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/history.md \
		${WRKSRC}/pro-tips.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
