# New ports collection makefile for:	SOAP4R
# Date created:		31 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	soap
PORTVERSION=	1.4.2
CATEGORIES=	net ruby
MASTER_SITES=	http://www.jin.gr.jp/~nahi/Ruby/SOAP4R/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}4r-${PORTVERSION:S/./_/g}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/application.rb:${PORTSDIR}/sysutils/ruby-application.rb \
		${RUBY_SITELIBDIR}/uri.rb:${PORTSDIR}/net/ruby-uri \
		${RUBY_SITELIBDIR}/http-access2.rb:${PORTSDIR}/www/ruby-http-access \
		${RUBY_SITELIBDIR}/GServer.rb:${PORTSDIR}/net/ruby-gserver \
		${RUBY_SITELIBDIR}/date3.rb:${PORTSDIR}/devel/ruby-date2 \
		${RUBY_SITELIBDIR}/nqxml/info.rb:${PORTSDIR}/textproc/ruby-nqxml

USE_RUBY=	yes

NO_BUILD=	yes

DOCS_EN=	RELEASE_en.html rubyStyle.css
DOCS_JA=	RELEASE_ja.html

post-extract:
	${CP} ${WRKSRC}/redist/soap/httpserver.rb ${WRKSRC}/sample/

post-patch:
	${RUBY} -i -pe 'gsub /\brubyStyle.css\b/, "../\\1"' ${WRKSRC}/RELEASE_ja.html

do-install:
	${CP} -R ${WRKSRC}/lib/* ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/sample/* ${WRKSRC}/test ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>
