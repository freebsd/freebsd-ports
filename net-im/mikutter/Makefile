# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mikutter
PORTVERSION=	3.0.9
CATEGORIES=	net-im ruby
MASTER_SITES=	http://mikutter.hachune.net/bin/ \
		LOCAL
MASTER_SITE_SUBDIR=	tota/${PORTNAME}
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple, powerful, and moeful Twitter client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gtk2>=2.2.0:${PORTSDIR}/x11-toolkits/rubygem-gtk2 \
		rubygem-cairo>=1.12.9:${PORTSDIR}/graphics/rubygem-cairo \
		rubygem-addressable>=2.3.6:${PORTSDIR}/www/rubygem-addressable \
		rubygem-hmac>=0.4.0:${PORTSDIR}/security/rubygem-hmac \
		rubygem-json_pure>=1.8.1:${PORTSDIR}/devel/rubygem-json_pure \
		rubygem-memoize>=1.3.1:${PORTSDIR}/devel/rubygem-memoize \
		rubygem-oauth>=0.4.7:${PORTSDIR}/net/rubygem-oauth \
		${RUBY_PKGNAMEPREFIX}bsearch>=1.5:${PORTSDIR}/devel/ruby-bsearch \
		rubygem-typed-array>=0.1.2:${PORTSDIR}/devel/rubygem-typed-array \
		rubygem-delayer>=0.0.2:${PORTSDIR}/devel/rubygem-delayer \
		rubygem-gettext>=2.3.1:${PORTSDIR}/devel/rubygem-gettext

WRKSRC=	${WRKDIR}/${PORTNAME}

USE_RUBY=	yes
NO_BUILD=	yes

RUBY_SHEBANG_FILES=	mikutter.rb \
			core/miku/miku.rb \
			core/lib/piapro.rb \
			devel/makechi.rb

PORTDOCS=	README
SUB_FILES=	mikutter.desktop
SUB_LIST=	RUBY_SITELIBDIR=${RUBY_SITELIBDIR}

REINPLACE_ARGS=	-i ''

OPTIONS_DEFINE=		DOCS HTTPCLIENT NOTIFY
HTTPCLIENT_DESC=	httpclient support
NOTIFY_DESC=		notify-send support

OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

HTTPCLIENT_RUN_DEPENDS=	rubygem-httpclient>=0:${PORTSDIR}/www/rubygem-httpclient
NOTIFY_RUN_DEPENDS=	notify-send:${PORTSDIR}/devel/libnotify

post-patch:
	@${REINPLACE_CMD} -e "s|%%RUBY_SITELIBDIR%%|${RUBY_SITELIBDIR}|" \
		${WRKSRC}/mikutter.rb
	@${RM} -r ${WRKSRC}/vendor

do-install:
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/mikutter.rb ${STAGEDIR}${PREFIX}/bin/mikutter
	cd ${INSTALL_WRKSRC} \
		&& ${COPYTREE_SHARE} core ${STAGEDIR}${RUBY_SITELIBDIR}/mikutter \
		&& ${COPYTREE_SHARE} plugin ${STAGEDIR}${RUBY_SITELIBDIR}/mikutter
	${INSTALL_DATA} ${WRKDIR}/${SUB_FILES} ${STAGEDIR}${PREFIX}/share/applications/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

x-generate-plist: stage
	${ECHO} bin/mikutter > pkg-plist.new
	${FIND} ${STAGEDIR}${RUBY_SITELIBDIR}/mikutter -type f | ${SORT} | ${SED} -e 's,${STAGEDIR}${RUBY_SITELIBDIR},%%RUBY_SITELIBDIR%%,' >> pkg-plist.new
	${ECHO} share/applications/mikutter.desktop >> pkg-plist.new

.include <bsd.port.mk>
