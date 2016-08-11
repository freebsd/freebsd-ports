# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	diff-lcs
PORTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	LCS-based diff library for ruby

LICENSE=	ART20 GPLv2 GPLv3 MIT
LICENSE_COMB=	dual

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem shebangfix
ruby_OLD_CMD=	ruby
SHEBANG_FILES=	bin/htmldiff bin/ldiff

PLIST_FILES=	bin/htmldiff bin/ldiff

.include <bsd.port.mk>
