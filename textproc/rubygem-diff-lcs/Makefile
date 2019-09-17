# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	diff-lcs
PORTVERSION=	1.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	LCS-based diff library for ruby

LICENSE=	ART20 GPLv2+ MIT
LICENSE_COMB=	dual
LICENSE_FILE_ART20=	${WRKSRC}/docs/artistic.txt
LICENSE_FILE_GPLv2+ =	${WRKSRC}/docs/COPYING.txt
LICENSE_FILE_MIT=	${WRKSRC}/License.md

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix

PLIST_FILES=	bin/htmldiff bin/ldiff

SHEBANG_FILES=	bin/htmldiff bin/ldiff
ruby_OLD_CMD=	ruby

.include <bsd.port.mk>
