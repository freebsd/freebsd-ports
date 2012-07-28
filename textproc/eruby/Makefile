# New ports collection makefile for:	eruby
# Date created:			14 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	eruby
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	textproc www ruby
MASTER_SITES=	http://www.modruby.net/archive/ \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Interprets Ruby code embedded in a text file like PHP/ePerl/ASP/JSP

USE_RUBY=	yes

CONFIGURE_ARGS=	--enable-shared --with-charset="${DEFAULT_CHARSET}"
INSTALL_TARGET=	site-install
USE_LDCONFIG=	yes

DEFAULT_CHARSET?=	ISO-8859-1

MAN1=		eruby.1

RUBY_RD_FILES=	eruby.rd

DOCS_EN=	COPYING ChangeLog README.en \
		${RUBY_RD_FILES} \
		${RUBY_RD_HTML_FILES}
DOCS_JA=	README.ja

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} configure.rb ${CONFIGURE_ARGS}

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PTHREADS)
.if ${RUBY_VERSION} == 1.8.7.160
# ruby18 -r rbconfig -e "p Config::CONFIG['LIBS']"  should output:
# "-lcrypt -lm  -rpath=/usr/lib:/usr/local/lib -pthread"
# but 1.8.7.160 missing pthread
CONFIGURE_ENV+=	EXTRA_LDFLAGS="${EXTRA_LDFLAGS} -pthread"
.endif
.endif

.if ${RUBY_VER} == "1.9"
CONFIGURE_ENV+=	EXTRA_CFLAGS="${EXTRA_CFLAGS} -DWITH_RUBY_19"
.endif

.include <bsd.port.post.mk>
