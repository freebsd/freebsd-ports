# New ports collection makefile for:	Ruby/XML-RPC
# Date created:		9 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	xmlrpc
PORTVERSION=	1.7.9
CATEGORIES=	net ruby
MASTER_SITES=	http://www.fantasy-coders.de/ruby/xmlrpc4r/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}4r-${PORTVERSION:S/./_/g}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITELIBDIR}/nqxml/info.rb:${PORTSDIR}/textproc/ruby-nqxml \
		${RUBY_SITELIBDIR}/TCPSocketPipe.rb:${PORTSDIR}/net/ruby-tcpsocketpipe \
		${RUBY_SITELIBDIR}/GServer.rb:${PORTSDIR}/net/ruby-gserver
# Alternative to ruby-nqxml:
#		${RUBY_SITELIBDIR}/xmlparser.rb:${PORTSDIR}/textproc/ruby-xmlparser

USE_RUBY=	yes

NO_BUILD=	yes

DOCS_EN=	ChangeLog README ToDo doc/*.css doc/*.html doc/*.rd

post-extract:
	${RM} -rf ${WRKSRC}/samples/monitor

post-patch:
	${RUBY} -i -pe '$$_ = "FILES2 = []\n" if /^FILES2\s*=/' ${WRKSRC}/install.rb

do-install:
	cd ${WRKSRC} && ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/samples/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${LN} -sf ../tcpsocketpipe ${RUBY_EXAMPLESDIR}/${PORTNAME}/monitor
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
