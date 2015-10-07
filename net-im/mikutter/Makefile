# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mikutter
PORTVERSION=	3.2.7
CATEGORIES=	net-im ruby
MASTER_SITES=	http://mikutter.hachune.net/bin/ \
		LOCAL/tota/${PORTNAME}
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple, powerful, and moeful Twitter client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gtk2>=2.2.5:${PORTSDIR}/x11-toolkits/rubygem-gtk2 \
		rubygem-cairo>=1.12.9:${PORTSDIR}/graphics/rubygem-cairo \
		rubygem-addressable>=2.3.8:${PORTSDIR}/www/rubygem-addressable \
		rubygem-ruby-hmac>=0.4.0:${PORTSDIR}/security/rubygem-ruby-hmac \
		rubygem-json_pure>=1.8.2:${PORTSDIR}/devel/rubygem-json_pure \
		rubygem-memoize>=1.3.1:${PORTSDIR}/devel/rubygem-memoize \
		rubygem-oauth>=0.4.7:${PORTSDIR}/net/rubygem-oauth \
		rubygem-typed-array>=0.1.2:${PORTSDIR}/devel/rubygem-typed-array \
		rubygem-delayer>=0.0.2:${PORTSDIR}/devel/rubygem-delayer \
		rubygem-gettext>=2.3.1:${PORTSDIR}/devel/rubygem-gettext \
		rubygem-moneta>=0.7:${PORTSDIR}/devel/rubygem-moneta \
		rubygem-nokogiri>=1.6.3.1:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-httpclient>=0:${PORTSDIR}/www/rubygem-httpclient

WRKSRC=	${WRKDIR}/${PORTNAME}

NO_ARCH=	yes
USE_RUBY=	yes
USES=	shebangfix
NO_BUILD=	yes

SHEBANG_FILES=	mikutter.rb \
		core/miku/miku.rb \
		core/lib/piapro.rb \
		devel/makechi.rb

PORTDOCS=	README
SUB_FILES=	mikutter.desktop
SUB_LIST=	RUBY_SITELIBDIR=${RUBY_SITELIBDIR}

REINPLACE_ARGS=	-i ''

OPTIONS_DEFINE=		DOCS NOTIFY
NOTIFY_DESC=		notify-send support

OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

.include <bsd.port.options.mk>

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
