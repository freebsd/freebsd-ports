PORTNAME=	diff-so-fancy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.10
CATEGORIES=	textproc

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Fancier diff output formatter
WWW=		https://github.com/so-fancy/diff-so-fancy/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git
TEST_DEPENDS=	bats:devel/bats-core

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	so-fancy
USE_PERL5=	run

SHEBANG_FILES=	${WRKSRC}/diff-so-fancy

TEST_TARGET=	test

TESTING_UNSAFE=	yes

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

PORTDOCS=	docs/*.md README.md

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_SCRIPT} ${WRKSRC}/diff-so-fancy ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/lib/DiffHighlight.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${WRKSRC} && bats test

.include <bsd.port.mk>
