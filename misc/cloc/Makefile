PORTNAME=	cloc
PORTVERSION=	2.06
CATEGORIES=	misc
MASTER_SITES=	https://github.com/AlDanial/cloc/releases/download/v${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Count lines of code
WWW=		https://github.com/AlDanial/cloc

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Algorithm-Diff>=0:devel/p5-Algorithm-Diff

USES=		perl5 shebangfix
USE_PERL5=	run

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/cloc

SHEBANG_FILES=	cloc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cloc ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
