# New ports collection makefile for:	eruby
# Date created:			14 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	eruby
PORTVERSION=	${VERSION}
PORTREVISION=	${REVISION}
CATEGORIES=	textproc www ruby
MASTER_SITES=	http://www.modruby.net/archive/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
RUBY_REQUIRE=	160 <= Ruby

.include <bsd.port.pre.mk>

.if defined(RUBY_PROVIDED)
VERSION=	0.1.3
.else
VERSION=	0.1.1
REVISON=	1
.endif

CONFIGURE_ARGS=	--enable-shared --default-charset="${DEFAULT_CHARSET}"
INSTALLS_SHLIB=	yes

DEFAULT_CHARSET?=	ISO-8859-1

MAN1=		eruby.1

DOCS_EN=	ChangeLog README.en
DOCS_JA=	README.ja

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} Makefile.RB ${CONFIGURE_ARGS}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/eruby/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/eruby/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/eruby/ja/
.endfor
.endif

.include <bsd.port.post.mk>
