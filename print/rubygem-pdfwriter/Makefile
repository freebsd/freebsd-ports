# Ports collection makefile for:	gem-pdfwriter
# Date created:				09 nov 2005
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	pdfwriter
PORTVERSION=	1.1.8
CATEGORIES=	print rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	ruby-pdf
DISTNAME=	pdf-writer-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A pure Ruby PDF document creation library

BUILD_DEPENDS=	rubygem-color>=1.4.0:${PORTSDIR}/print/rubygem-color \
		rubygem-transactionsimple>=1.4.0:${PORTSDIR}/devel/rubygem-transactionsimple
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${DISTNAME}
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/techbook

.include <bsd.port.mk>
