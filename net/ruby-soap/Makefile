# New ports collection makefile for:	SOAP4R
# Date created:		31 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	soap
PORTVERSION=	1.4.3
CATEGORIES=	net ruby
MASTER_SITES=	http://www.jin.gr.jp/~nahi/Ruby/SOAP4R/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}4r-${PORTVERSION:S/./_/g}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/application.rb:${PORTSDIR}/sysutils/ruby-devel-logger \
		${RUBY_SITELIBDIR}/http-access2.rb:${PORTSDIR}/www/ruby-http-access \
		${RUBY_SITELIBDIR}/GServer.rb:${PORTSDIR}/net/ruby-gserver \
		${RUBY_SITELIBDIR}/date2.rb:${PORTSDIR}/devel/ruby-date2 \
		${RUBY_SITELIBDIR}/nqxml/info.rb:${PORTSDIR}/textproc/ruby-nqxml

USE_RUBY=	yes

NO_BUILD=	yes

DOCS_EN=	RELEASE_en.html rubyStyle.css

post-extract:
	${CP} ${WRKSRC}/redist/soap/httpserver.rb ${WRKSRC}/sample/

do-install:
	${CP} -R ${WRKSRC}/lib/* ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/sample/* ${WRKSRC}/test ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
