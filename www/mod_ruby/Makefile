# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	mod_ruby
PORTVERSION=	1.3.0
PORTREVISION=	3
CATEGORIES=	www ruby
MASTER_SITES=	ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An Apache module that embeds Ruby interpreter within

USES=		perl5
USE_APACHE=	22
USE_RUBY=	yes
USE_PERL5=	build

CONFIGURE_ARGS=	--with-apxs="${APXS}" \
		--with-apr-includes="`${LOCALBASE}/bin/apr-1-config --includedir`"
CFLAGS+=	-DONIG_ESCAPE_REGEX_T_COLLISION
MAKE_ARGS=	RUBY="${RUBY}"
INSTALL_TARGET=	site-install

RUBY_RD_FILES=	# empty

DOCS_EN=	COPYING ChangeLog LEGAL LICENSE.apreq NOTICE \
		README.en doc/default.css doc/*.en.*
DOCS_JA=	README.ja doc/default.css doc/*.ja.*

OPTIONS_DEFINE=	PTHREADS DOCS EXAMPLES
OPTIONS_DEFAULT=
NO_OPTIONS_SORT=yes
OPTIONS_SUB=yes
PTHREADS_DESC=	Build threaded module

.include <bsd.port.options.mk>

do-configure:
	cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_FLAGS} \
		configure.rb ${CONFIGURE_ARGS}
.if ${PORT_OPTIONS:MPTHREADS}
# dirty hack to force mod_ruby.so linked with lpthread.so, otherwise unresolved
# symbols happen
	${REINPLACE_CMD} -e 's|-pthread|-pthread -lpthread|' ${WRKSRC}/Makefile

PKGNAMESUFFIX=	-pthreads
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/httpd.conf \
		${STAGEDIR}${EXAMPLESDIR}/httpd.conf
.endif

.include <bsd.port.mk>
