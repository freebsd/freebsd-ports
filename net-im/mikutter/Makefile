# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mikutter
PORTVERSION=	0.2.2.1410
CATEGORIES=	net-im ruby
MASTER_SITES=	http://mikutter.hachune.net/bin/ \
		LOCAL
MASTER_SITE_SUBDIR=	tota/${PORTNAME}
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple, powerful, and moeful Twitter client

LICENSE=	GPLv3

RUN_DEPENDS=	rubygem-gtk2>=1.5.0:${PORTSDIR}/x11-toolkits/rubygem-gtk2 \
		graphics/rubygem-cairo>=1.10.0:${PORTSDIR}/graphics/rubygem-cairo \
		rubygem-addressable>=2.2.7:${PORTSDIR}/www/rubygem-addressable \
		rubygem-hmac>=0.4.0:${PORTSDIR}/security/rubygem-hmac \
		rubygem-json>=1.8.0:${PORTSDIR}/devel/rubygem-json \
		${RUBY_SITELIBDIR}/memoize.rb:${PORTSDIR}/devel/ruby-memoize \
		rubygem-oauth>=0.4.7:${PORTSDIR}/net/rubygem-oauth \
		${RUBY_SITELIBDIR}/bsearch.rb:${PORTSDIR}/devel/ruby-bsearch \
		rubygem-typed-array>=0.1.2:${PORTSDIR}/devel/rubygem-typed-array

WRKSRC=	${WRKDIR}/${PORTNAME}

USE_RUBY=	yes
NO_BUILD=	yes

RUBY_REQUIRE=	Ruby >= 193
RUBY_SHEBANG_FILES=	mikutter.rb \
			core/miku/miku.rb \
			devel/makechi.rb

SUB_FILES=	mikutter.desktop
SUB_LIST=	RUBY_SITELIBDIR=${RUBY_SITELIBDIR}

PORTDOCS=	README

OPTIONS_DEFINE=		HTTPCLIENT NOTIFY
HTTPCLIENT_DESC=	httpclient support
NOTIFY_DESC=		notify-send support

OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHTTPCLIENT}
RUN_DEPENDS+=	rubygem-httpclient>=0:${PORTSDIR}/www/rubygem-httpclient
.endif

.if ${PORT_OPTIONS:MNOTIFY}
RUN_DEPENDS+=	notify-send:${PORTSDIR}/devel/libnotify
.endif

post-patch:
	@${REINPLACE_CMD} -i '' -e "s|%%RUBY_SITELIBDIR%%|${RUBY_SITELIBDIR}|" \
		${WRKSRC}/mikutter.rb
	@${RM} -r ${WRKSRC}/vendor

do-install:
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/mikutter.rb ${STAGEDIR}${PREFIX}/bin/mikutter
	cd ${INSTALL_WRKSRC} \
		&& ${COPYTREE_SHARE} core ${STAGEDIR}${RUBY_SITELIBDIR}/mikutter \
		&& ${COPYTREE_SHARE} plugin ${STAGEDIR}${RUBY_SITELIBDIR}/mikutter
	${INSTALL_DATA} ${WRKDIR}/${SUB_FILES} ${STAGEDIR}${PREFIX}/share/applications/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

x-generate-plist:
	${ECHO} bin/mikutter > pkg-plist.new
	${FIND} ${RUBY_SITELIBDIR}/mikutter -type f | ${SORT} | ${SED} -e 's,${RUBY_SITELIBDIR},%%RUBY_SITELIBDIR%%,' >> pkg-plist.new
	${ECHO} share/applications/mikutter.desktop >> pkg-plist.new
	${FIND} ${RUBY_SITELIBDIR}/mikutter -type d -depth | ${SORT} -r | ${SED} -e 's,${RUBY_SITELIBDIR},@dirrm %%RUBY_SITELIBDIR%%,' >> pkg-plist.new

.include <bsd.port.mk>
