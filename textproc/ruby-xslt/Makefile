# New ports collection makefile for:	ruby-xmlscan
# Date created:		22 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xslt
PORTVERSION=	0.0.1
CATEGORIES=	textproc ruby
MASTER_SITES=	 http://www.fantasy-coders.de/ruby/xslt4r/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}4r-${PORTVERSION:S/./_/g}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/xpathtree.rb:${PORTSDIR}/textproc/ruby-xmlscan

USE_RUBY=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/xslt.rb

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xslt.rb ${RUBY_SITELIBDIR}/
	${LN} -sf ${RUBY_SITELIBDIR}/xslt.rb ${LOCALBASE}/bin/xslt
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/test/*.x* ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/ToDo ${RUBY_DOCDIR}/${PORTNAME}
.endif

.include <bsd.port.mk>
