# New ports collection makefile for:	eruby
# Date created:			14 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	eruby
PORTVERSION=	0.9.8
CATEGORIES=	textproc www ruby
MASTER_SITES=	http://www.modruby.net/archive/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_RDTOOL=	yes

CONFIGURE_ARGS=	--enable-shared --with-charset="${DEFAULT_CHARSET}"
INSTALL_TARGET=	site-install
INSTALLS_SHLIB=	yes

DEFAULT_CHARSET?=	ISO-8859-1

MAN1=		eruby.1

DOCS_EN=	COPYING ChangeLog README.en eruby.html eruby.rd
DOCS_JA=	README.ja

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} configure.rb ${CONFIGURE_ARGS}

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; ${RUBY_RD2} eruby.rd > eruby.html
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>
