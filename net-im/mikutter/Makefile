# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mikutter
PORTVERSION=	3.4.1
CATEGORIES=	net-im ruby
MASTER_SITES=	http://mikutter.hachune.net/bin/ \
		LOCAL/tota/${PORTNAME}
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Simple, powerful, and moeful Twitter client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-gtk2>=3.0.7:x11-toolkits/rubygem-gtk2 \
		rubygem-cairo>=1.12.9:graphics/rubygem-cairo \
		rubygem-addressable>=2.4.0:www/rubygem-addressable \
		rubygem-delayer>=0.0.2:devel/rubygem-delayer \
		rubygem-delayer-deferred>=1.0.3:devel/rubygem-delayer-deferred \
		rubygem-gettext>=3.0.9:devel/rubygem-gettext \
		rubygem-httpclient>=2.7.1:www/rubygem-httpclient \
		rubygem-instance_storage>=1.0.0:devel/rubygem-instance_storage \
		rubygem-json_pure>=1.8.3:devel/rubygem-json_pure \
		rubygem-locale>=2.1.1:devel/rubygem-locale \
		rubygem-memoist>=0.14.0:devel/rubygem-memoist \
		rubygem-moneta>=0.7:devel/rubygem-moneta \
		rubygem-nokogiri>=1.6.7:textproc/rubygem-nokogiri \
		rubygem-oauth>=0.5.1:net/rubygem-oauth \
		rubygem-pluggaloid>=1.1.1:devel/rubygem-pluggaloid \
		rubygem-ruby-hmac>=0.4.0:security/rubygem-ruby-hmac \
		rubygem-text>=1.3.1:textproc/rubygem-text \
		rubygem-totoridipjp>=0.1.0:www/rubygem-totoridipjp \
		rubygem-twitter-text>=1.13.0:textproc/rubygem-twitter-text \
		rubygem-typed-array>=0.1.2:devel/rubygem-typed-array \
		rubygem-unf>=0.1.4:textproc/rubygem-unf

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
