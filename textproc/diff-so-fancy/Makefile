# $FreeBSD$

PORTNAME=	diff-so-fancy
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Fancier diff output formatter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

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
