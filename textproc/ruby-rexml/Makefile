# New ports collection makefile for:	REXML
# Date created:		15 October 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rexml
PORTVERSION=	1.2.5
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.germane-software.com/~ser/Software/archives/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

DOCS=		README index.html tutorial.html api img

do-install:
	cd ${WRKSRC} && ${RUBY} bin/install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
