# New ports collection makefile for:	Ruby/XML-RPC
# Date created:		9 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xmlrpc
PORTVERSION=	1.7.12
CATEGORIES=	net ruby
MASTER_SITES=	http://www.fantasy-coders.de/ruby/xmlrpc4r/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}4r-${PORTVERSION:S/./_/g}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/xmlparser.so:${PORTSDIR}/textproc/ruby-xmlparser \
		${RUBY_SITELIBDIR}/TCPSocketPipe.rb:${PORTSDIR}/net/ruby-tcpsocketpipe \
		${RUBY_SITELIBDIR}/GServer.rb:${PORTSDIR}/net/ruby-gserver
# Alternative to ruby-xmlparser:
#     NQXML
#		${RUBY_SITELIBDIR}/nqxml/info.rb:${PORTSDIR}/textproc/ruby-nqxml
#     REXML
#		${RUBY_SITELIBDIR}/rexml/rexml.rb:${PORTSDIR}/textproc/ruby-rexml

USE_RUBY=	yes

NO_BUILD=	yes

DOCS_EN=	ChangeLog README ToDo doc/*.css doc/*.html doc/*.rd

post-extract:
	${RM} -rf ${WRKSRC}/samples/monitor

post-patch:
	${RUBY} -i -pe '$$_ = "FILES2 = []\n" if /^FILES2\s*=/' ${WRKSRC}/install.rb

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/* ${RUBY_MODEXAMPLESDIR}/
	${LN} -sf ../tcpsocketpipe ${RUBY_MODEXAMPLESDIR}/monitor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
