# New ports collection makefile for:	mod_ruby
# Date created:			12 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mod_ruby
PORTVERSION=	0.1.9
CATEGORIES=	www ruby
MASTER_SITES=	http://www.ruby-lang.org/~shugo/mod_ruby/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

USE_RUBY=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

APXS=		${LOCALBASE}/sbin/apxs

DOCS_EN=	ChangeLog README.en
DOCS_JA=	README.ja

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} Makefile.RB

do-install:
	${APXS} -i -A -n ruby ${WRKSRC}/mod_ruby.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/mod_ruby/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/mod_ruby/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/mod_ruby/ja/
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
.include <bsd.port.post.mk>
