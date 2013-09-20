# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	crypt
PORTVERSION=	1.1.4
CATEGORIES=	security ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Pure-ruby implementation of popular encryption algorithms

USE_RUBY=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

NO_STAGE=	yes
do-install:
	@cd ${WRKSRC}; ${RUBY} install.rb

.include <bsd.port.mk>
