# New ports collection makefile for:	mod_ruby
# Date created:			12 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mod_ruby
PORTVERSION=	1.0.1
CATEGORIES=	www ruby
MASTER_SITES=	http://www.modruby.net/archive/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
LIB_DEPENDS=	eruby.09:${PORTSDIR}/textproc/eruby
RUN_DEPENDS=	${APXS}:${APACHE_PORT}

USE_RUBY=	yes
USE_RUBY_RDTOOL=	yes

APXS?=		${LOCALBASE}/sbin/apxs
APACHE_PORT?=	${PORTSDIR}/www/apache13

CONFIGURE_ARGS=	--with-apxs="${APXS}" \
		--enable-eruby=yes \
		--with-eruby-includes="${LOCALBASE}/include" \
		--with-eruby-libraries="${LOCALBASE}/lib"
INSTALL_TARGET=	site-install

DOCS_EN=	COPYING ChangeLog README.en doc/default.css doc/*.en.*
DOCS_JA=	README.ja doc/default.css doc/*.ja.*

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_FLAGS} configure.rb ${CONFIGURE_ARGS}

post-build:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/doc; ${MAKE}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/httpd.conf `${APXS} -q SYSCONFDIR`/httpd.conf.${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
