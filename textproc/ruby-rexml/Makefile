# New ports collection makefile for:	REXML
# Date created:		15 October 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rexml
PORTVERSION=	2.4.5
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.germane-software.com/software/archives/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

DOCS=		README *.html doc

do-install:
	cd ${WRKSRC}; ${RUBY} bin/install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/docs
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${RUBY_MODDOCDIR}/docs/
.endif

.include <bsd.port.mk>
