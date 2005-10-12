# New ports collection makefile for:	sitemapgen
# Date Created:				12 Oct 2005
# Whom:					ceri
#
# $FreeBSD$
#

PORTNAME=	sitemapgen
PORTVERSION=	1.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	goog-sitemapgen
DISTNAME=	sitemap_gen-${PORTVERSION}

MAINTAINER=	ceri@FreeBSD.org
COMMENT=	A Google sitemap generator

USE_PYTHON=	yes

NOMAN=		yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sitemap_gen.py ${PREFIX}/bin/sitemap_gen
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for DOC in AUTHORS COPYING ChangeLog PKG-INFO README example_config.xml example_urllist.txt
	${INSTALL} ${WRKSRC}/${DOC} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
