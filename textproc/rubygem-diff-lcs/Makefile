PORTNAME=	diff-lcs
PORTVERSION=	1.5.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	LCS-based diff library for ruby

LICENSE=	ART20 GPLv2+ MIT
LICENSE_COMB=	dual
LICENSE_FILE_ART20=	${WRKSRC}/docs/artistic.txt
LICENSE_FILE_GPLv2+ =	${WRKSRC}/docs/COPYING.txt
LICENSE_FILE_MIT=	${WRKSRC}/License.md

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/htmldiff bin/ldiff

CONFLICTS_INSTALL=	p5-HTML-Diff # bin/htmldiff

SHEBANG_FILES=	bin/htmldiff bin/ldiff
ruby_OLD_CMD=	ruby

.include <bsd.port.mk>
