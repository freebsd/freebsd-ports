# New ports collection makefile for:	eruby
# Date created:			14 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	eruby
PORTVERSION=	1.0.5
CATEGORIES=	textproc www ruby
MASTER_SITES=	http://www.modruby.net/archive/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Interprets Ruby code embedded in a text file like PHP/ePerl/ASP/JSP

USE_RUBY=	yes

CONFIGURE_ARGS=	--enable-shared --with-charset="${DEFAULT_CHARSET}"
INSTALL_TARGET=	site-install
INSTALLS_SHLIB=	yes

DEFAULT_CHARSET?=	ISO-8859-1

MAN1=		eruby.1

RUBY_RD_FILES=	eruby.rd

DOCS_EN=	COPYING ChangeLog README.en \
		${RUBY_RD_FILES} \
		${RUBY_RD_HTML_FILES}
DOCS_JA=	README.ja

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} configure.rb ${CONFIGURE_ARGS}

post-install: doc-install

.include <bsd.port.mk>

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif
