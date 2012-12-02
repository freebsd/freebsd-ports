# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mikutter
PORTVERSION=	0.2.0.1064
CATEGORIES=	net-im ruby
MASTER_SITES=	http://mikutter.hachune.net/bin/ \
		LOCAL
MASTER_SITE_SUBDIR=	tota/${PORTNAME}
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple, powerful, and moeful Twitter client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

INSTALL_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		${RUBY_SITEARCHLIBDIR}/cairo.so:${PORTSDIR}/graphics/ruby-cairo \
		rubygem-addressable>=2.2.7:${PORTSDIR}/www/rubygem-addressable \
		${RUBY_PKGNAMEPREFIX}hmac>=0.4.0:${PORTSDIR}/security/ruby-hmac \
		rubygem-json_pure>=0:${PORTSDIR}/devel/rubygem-json_pure \
		${RUBY_SITELIBDIR}/memoize.rb:${PORTSDIR}/devel/ruby-memoize \
		rubygem-oauth>=0:${PORTSDIR}/net/rubygem-oauth \
		${RUBY_SITELIBDIR}/bsearch.rb:${PORTSDIR}/devel/ruby-bsearch \
		rubygem-typed-array>=0.1.2:${PORTSDIR}/devel/rubygem-typed-array

WRKSRC=	${WRKDIR}/${PORTNAME}

USE_RUBY=	yes
RUBY_VER=	1.9
NO_BUILD=	yes

CONFLICTS=	mikutter-0.0.3.*

RUBY_SHEBANG_FILES=	mikutter.rb \
			core/autotag.rb \
			core/chi.rb \
			core/initialize.rb \
			core/lib/piapro.rb \
			core/miku/miku.rb

SUB_FILES=	mikutter.desktop
SUB_LIST=	RUBY_SITELIBDIR=${RUBY_SITELIBDIR}

PORTDOCS=	README

OPTIONS_DEFINE=		HTTPCLIENT NOTIFY
HTTPCLIENT_DESC=	httpclient support
NOTIFY_DESC=		notify-send support

OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

.include <bsd.port.pre.mk>

.if ${RUBY_DEFAULT_VER} != ${RUBY_VER}
IGNORE=	requires RUBY_DEFAULT_VER=${RUBY_VER}
.endif

.if ${PORT_OPTIONS:MHTTPCLIENT}
RUN_DEPENDS+=	rubygem-httpclient>=0:${PORTSDIR}/www/rubygem-httpclient
.endif

.if ${PORT_OPTIONS:MNOTIFY}
RUN_DEPENDS+=	notify-send:${PORTSDIR}/devel/libnotify
.endif

post-patch:
	@${REINPLACE_CMD} -i '' -e "s|%%RUBY_SITELIBDIR%%|${RUBY_SITELIBDIR}|" \
		${WRKSRC}/mikutter.rb
	@${REINPLACE_CMD} -i '' -e "s|miquire :lib, 'ruby-bsearch-1.5/bsearch'|require 'bsearch'|" \
		${WRKSRC}/core/mui/cairo_inner_tl.rb
	@${RM} -rf ${WRKSRC}/core/lib/hmac*
	@${RM} -rf ${WRKSRC}/core/lib/json*
	@${RM} -rf ${WRKSRC}/core/lib/memoize.rb
	@${RM} -rf ${WRKSRC}/core/lib/oauth*
	@${RM} -rf ${WRKSRC}/core/lib/ruby-bsearch-1.5
	@${RM} -rf ${WRKSRC}/vendor/addressable
	@${RM} -rf ${WRKSRC}/vendor/hmac*
	@${RM} -rf ${WRKSRC}/vendor/json*
	@${RM} -rf ${WRKSRC}/vendor/memoize.rb
	@${RM} -rf ${WRKSRC}/vendor/oauth*
	@${RM} -rf ${WRKSRC}/vendor/ruby-bsearch-1.5
	@${RM} -rf ${WRKSRC}/vendor/typed-array*

do-install:
	@${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/mikutter.rb ${PREFIX}/bin/mikutter
	@cd ${INSTALL_WRKSRC} \
		&& ${COPYTREE_SHARE} core ${RUBY_SITELIBDIR}/mikutter \
		&& ${COPYTREE_SHARE} plugin ${RUBY_SITELIBDIR}/mikutter \
		&& ${COPYTREE_SHARE} vendor ${RUBY_SITELIBDIR}/mikutter
	@${MKDIR} ${PREFIX}/share/applications
	@${INSTALL_DATA} ${WRKDIR}/${SUB_FILES} ${PREFIX}/share/applications/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

x-generate-plist:
	${ECHO} bin/mikutter > pkg-plist.new
	${FIND} ${RUBY_SITELIBDIR}/mikutter -type f | ${SORT} | ${SED} -e 's,${RUBY_SITELIBDIR},%%RUBY_SITELIBDIR%%,' >> pkg-plist.new
	${ECHO} share/applications/mikutter.desktop >> pkg-plist.new
	${ECHO} '@dirrmtry share/applications' >> pkg-plist.new
	${FIND} ${RUBY_SITELIBDIR}/mikutter -type d -depth | ${SORT} -r | ${SED} -e 's,${RUBY_SITELIBDIR},@dirrm %%RUBY_SITELIBDIR%%,' >> pkg-plist.new

.include <bsd.port.post.mk>
