# New ports collection makefile for:	Ruby-TMail
# Date created:		22 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	tmail
PORTVERSION=	0.8.12
CATEGORIES=	mail ruby
MASTER_SITES=	http://www1.u-netsurf.ne.jp/~brew/mine/soft/
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		${RUBY_SITELIBDIR}/amstd/info.rb:${PORTSDIR}/devel/ruby-amstd
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		${RUBY_SITELIBDIR}/amstd/info.rb:${PORTSDIR}/devel/ruby-amstd \
		${RUBY_SITELIBDIR}/racc/parser.rb:${PORTSDIR}/devel/ruby-racc-runtime \
		${RUBY_SITEARCHLIBDIR}/strscan.so:${PORTSDIR}/devel/ruby-strscan

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

RUBY_SITELIBDIR?=	${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}
RUBY_SITEARCHLIBDIR?=	${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}/${RUBY_ARCH}

post-patch:
	${PERL} -i -ne '/\btmail\b/ and print' \
		${WRKSRC}/ext/PATHCONV ${WRKSRC}/lib/PATHCONV
	for d in cparse strscanso; do ${RM} -rf ${WRKSRC}/ext/$$d; done
	for d in amstd raccrt strscan; do ${RM} -rf ${WRKSRC}/lib/$$d; done

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${RUBY} setup.rb config

do-build:
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} setup.rb setup

do-install:
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} setup.rb install
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/tmail
	${CP} -R ${WRKSRC}/sample/ ${PREFIX}/share/examples/ruby/tmail/
	${MKDIR} ${PREFIX}/share/doc/ruby/tmail/ja
	${CP} -R ${WRKSRC}/README.en ${WRKSRC}/doc.en/ ${PREFIX}/share/doc/ruby/tmail/
	${CP} -R ${WRKSRC}/README.ja ${WRKSRC}/doc.ja/ ${PREFIX}/share/doc/ruby/tmail/ja/
.endif

.include <bsd.port.mk>
