# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	eruby
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	textproc www ruby
MASTER_SITES=	ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Interprets Ruby code embedded in a text file like PHP/ePerl/ASP/JSP

USE_RUBY=	yes

CONFIGURE_ARGS=	--enable-shared --with-charset="${DEFAULT_CHARSET}"
INSTALL_TARGET=	site-install
USE_LDCONFIG=	yes

DEFAULT_CHARSET?=	ISO-8859-1

RUBY_RD_FILES=	eruby.rd

DOCS_EN=	COPYING ChangeLog README.en \
		${RUBY_RD_FILES} \
		${RUBY_RD_HTML_FILES}
DOCS_JA=	README.ja

.include <bsd.port.pre.mk>

do-configure:
	cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} configure.rb ${CONFIGURE_ARGS}
	${REINPLACE_CMD} -e 's|^XLDFLAGS = .*|XLDFLAGS = -L${PREFIX}/lib|' \
		-e 's|-Wl,$$(libdir)|-Wl,${PREFIX}/lib|' \
		-e 's|-L$$(libdir)|-L${PREFIX}/lib|' \
		${WRKSRC}/Makefile

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
.endfor
.endif

CONFIGURE_ENV+=	EXTRA_CFLAGS="${EXTRA_CFLAGS} -DWITH_RUBY_19"

.include <bsd.port.post.mk>
