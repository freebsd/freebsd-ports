# New ports collection makefile for:	mod_ruby
# Date created:			12 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mod_ruby
PORTVERSION=	${RELEASE_VER}.${SNAPSHOT_DATE}
CATEGORIES=	www lang	# ruby
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13 \
		ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13 \
		ruby:${PORTSDIR}/lang/ruby

WRKSRC=		${WRKDIR}/${PORTNAME}

RELEASE_VER=	0.1.8
SNAPSHOT_DATE=	2000.08.04

APXS=		${LOCALBASE}/sbin/apxs

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

DOCS_EN=	ChangeLog README.en
DOCS_JA=	README.ja

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} Makefile.RB

do-install:
	${APXS} -i -A -n ruby ${WRKSRC}/mod_ruby.so
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/mod_ruby/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/mod_ruby/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/mod_ruby/ja/
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
