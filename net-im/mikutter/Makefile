# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mikutter
PORTVERSION=	3.6.4
CATEGORIES=	net-im ruby
MASTER_SITES=	http://mikutter.hachune.net/bin/ \
		LOCAL/tota/${PORTNAME}
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple, powerful, and moeful Twitter client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gtk2>=3.1.8:x11-toolkits/rubygem-gtk2 \
		rubygem-cairo>=1.12.9:graphics/rubygem-cairo \
		rubygem-addressable>=2.5.2:www/rubygem-addressable \
		rubygem-delayer>=0.0.2:devel/rubygem-delayer \
		rubygem-delayer-deferred>=2.0.0:devel/rubygem-delayer-deferred \
		rubygem-diva>=0.3.1:devel/rubygem-diva \
		rubygem-gettext>=3.0.9:devel/rubygem-gettext \
		rubygem-gio2>=3.1.0:devel/rubygem-gio2 \
		rubygem-httpclient>=2.7.1:www/rubygem-httpclient \
		rubygem-instance_storage>=1.0.0:devel/rubygem-instance_storage \
		rubygem-json_pure1>=1.8.6:devel/rubygem-json_pure1 \
		rubygem-locale>=2.1.2:devel/rubygem-locale \
		rubygem-memoist>=0.16.0:devel/rubygem-memoist \
		rubygem-moneta>=0.7:devel/rubygem-moneta \
		rubygem-nokogiri>=1.6.7:textproc/rubygem-nokogiri \
		rubygem-oauth>=0.5.4:net/rubygem-oauth \
		rubygem-pluggaloid>=1.1.1:devel/rubygem-pluggaloid \
		rubygem-public_suffix>=3.0.2:dns/rubygem-public_suffix \
		rubygem-ruby-hmac>=0.4.0:security/rubygem-ruby-hmac \
		rubygem-text>=1.3.1:textproc/rubygem-text \
		rubygem-totoridipjp>=0.1.0:www/rubygem-totoridipjp \
		rubygem-twitter-text>=2.1.0:textproc/rubygem-twitter-text \
		rubygem-typed-array>=0.1.2:devel/rubygem-typed-array \
		rubygem-unf>=0.1.4:textproc/rubygem-unf

WRKSRC=	${WRKDIR}/${PORTNAME}

NO_ARCH=	yes
USES=		shebangfix
USE_RUBY=	yes
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

NOTIFY_RUN_DEPENDS=	notify-send:devel/libnotify

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
