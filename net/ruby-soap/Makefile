# New ports collection makefile for:	SOAP4R
# Date created:		31 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	soap
PORTVERSION=	1.4.7
CATEGORIES=	net ruby
MASTER_SITES=	http://www.jin.gr.jp/~nahi/Ruby/SOAP4R/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}4r-${PORTVERSION:S/./_/g}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/application.rb:${PORTSDIR}/sysutils/ruby-devel-logger \
		${RUBY_SITELIBDIR}/http-access2.rb:${PORTSDIR}/www/ruby-http-access \
		${RUBY_SITELIBDIR}/GServer.rb:${PORTSDIR}/net/ruby-gserver \
		${RUBY_SITELIBDIR}/rexml/rexml.rb:${PORTSDIR}/textproc/ruby-rexml \
		${DEPEND_RUBY_DATE2}

USE_RUBY=	yes

NO_BUILD=	yes

DOCS_EN=	RELEASE_en.html ToDo rubyStyle.css

.include <bsd.port.pre.mk>

.if ${RUBY_VER} < 1.7
DEPEND_RUBY_DATE2=	${RUBY_SITELIBDIR}/date.rb:${PORTSDIR}/devel/ruby-date2
.endif

post-extract:
	${RM} -f ${WRKSRC}/redist/GServer.rb

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
	${INSTALL_SCRIPT} ${WRKSRC}/bin/wsdl2ruby.rb ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/* ${WRKSRC}/test ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
