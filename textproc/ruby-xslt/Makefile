# New ports collection makefile for:	ruby-xmlscan
# Date created:		22 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xslt
PORTVERSION=	0.0.2
CATEGORIES=	textproc ruby
MASTER_SITES=	 http://www.fantasy-coders.de/ruby/xslt4r/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}4r-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/xpathtree.rb:${PORTSDIR}/textproc/ruby-xmlscan

USE_RUBY=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/xslt.rb

NO_BUILD=	yes

DOCS=		ChangeLog ToDo

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xslt.rb ${RUBY_SITELIBDIR}/
	${LN} -sf ${RUBY_SITELIBDIR}/xslt.rb ${LOCALBASE}/bin/xslt
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/test/*.x* ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}
.endfor
.endif

.include <bsd.port.mk>
