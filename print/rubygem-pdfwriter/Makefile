# Ports collection makefile for:	gem-pdfwriter
# Date created:				09 nov 2005
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	pdfwriter
PORTVERSION=	1.1.3
CATEGORIES=	print rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	ruby-pdf
DISTNAME=	pdf-writer-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A pure Ruby PDF document creation library

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/color-tools-1.3.0.gemspec:${PORTSDIR}/${PKGCATEGORY}/rubygem-colortools
BUILD_DEPENDS+=	${LOCALBASE}/${SPEC_DIR}/transaction-simple-1.4.0.gemspec:${PORTSDIR}/devel/rubygem-transactionsimple
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
