# New ports collection makefile for:	mod_ruby
# Date created:			12 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mod_ruby
PORTVERSION=	1.3.0
CATEGORIES=	www ruby
MASTER_SITES=	http://www.modruby.net/archive/
DIST_SUBDIR=	ruby

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An Apache module that embeds Ruby interpreter within

LIB_DEPENDS=	eruby.10:${PORTSDIR}/textproc/eruby

MAKE_JOBS_SAFE=  yes

USE_APACHE=	1.3+
USE_RUBY=	yes
USE_PERL5_BUILD=	yes

CONFIGURE_ARGS=	--with-apxs="${APXS}" \
		--enable-eruby=yes \
		--with-eruby-includes="${LOCALBASE}/include" \
		--with-eruby-libraries="${LOCALBASE}/lib"
MAKE_ARGS=	RUBY="${RUBY}"
INSTALL_TARGET=	site-install

RUBY_RD_FILES=	# empty

DOCS_EN=	COPYING ChangeLog LEGAL LICENSE.apreq NOTICE \
		README.en doc/default.css doc/*.en.*
DOCS_JA=	README.ja doc/default.css doc/*.ja.*

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} > 20
CONFIGURE_ARGS+=	--with-apr-includes="`${LOCALBASE}/bin/apr-1-config --includedir`"
.endif

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_FLAGS} configure.rb ${CONFIGURE_ARGS}
.if !defined(WITHOUT_PTHREADS) && defined(WITH_PTHREADS)
# dirty hack to force mod_ruby.so linked with lpthread.so, otherwise unresolved
# symbols happen
	@${REINPLACE_CMD} -e 's|-pthread|-pthread -lpthread|' ${WRKSRC}/Makefile

PKGNAMESUFFIX=	-pthreads
.endif

post-install: doc-install
	${INSTALL_DATA} ${WRKSRC}/examples/httpd.conf `${APXS} -q SYSCONFDIR`/httpd.conf.${PORTNAME}
# Would be nice if we could use PLIST_SUB here..
	${REINPLACE_CMD} \
		-e 's,%%LIBEXECDIR%%,'`${APXS} -q LIBEXECDIR | ${SED} 's:${LOCALBASE}/::'`',g;' \
		-e 's,%%SYSCONFDIR%%,'`${APXS} -q SYSCONFDIR | ${SED} 's:${LOCALBASE}/::'`',g;' \
		${TMPPLIST}

doc-install:
.if !defined(NOPORTDOCS)
.if !defined(RUBY_NO_RD_HTML)
	cd ${WRKSRC}/doc; ${MAKE}
.endif
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
