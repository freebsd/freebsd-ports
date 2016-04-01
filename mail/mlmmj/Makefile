# Created by: Christian Laursen <xi@borderworlds.dk>
# $FreeBSD$

PORTNAME=	mlmmj
PORTVERSION=	1.2.17.1
CATEGORIES=	mail
MASTER_SITES=	http://mlmmj.org/releases/ \
		LOCAL/brix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mailing list managing made joyful

LICENSE=	MIT

USES=		cpe gmake tar:bzip2

.if defined(WITH_PHP_WEBINTERFACE)
USE_PHP=	yes
WANT_PHP_WEB=	yes
.endif

.if defined(WITH_PERL_WEBINTERFACE)
RUN_DEPENDS+=	p5-URI>=0:net/p5-URI \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-CGI-FastTemplate>=0:www/p5-CGI-FastTemplate
.endif

.if defined(WITH_PERL_WEBINTERFACE)
PLIST_SUB+=	PERLWEB=""
.else
PLIST_SUB+=	PERLWEB="@comment "
.endif

.if defined(WITH_PHP_WEBINTERFACE)
PLIST_SUB+=	PHPWEB=""
.else
PLIST_SUB+=	PHPWEB="@comment "
.endif

.if !defined(WITH_PERL_WEBINTERFACE) && !defined(WITH_PHP_WEBINTERFACE)
PLIST_SUB+=	WEB="@comment "
.else
PLIST_SUB+=	WEB=""
.endif

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/src/mlmmj-make-ml.sh

post-install:
.if defined(WITH_PERL_WEBINTERFACE)
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/mlmmj/perl-admin
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/perl-admin/README ${STAGEDIR}${PREFIX}/www/mlmmj/perl-admin
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/mlmmj/perl-admin/htdocs
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/web/perl-admin/htdocs/* ${STAGEDIR}${PREFIX}/www/mlmmj/perl-admin/htdocs
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/mlmmj/perl-admin/templates
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/perl-admin/templates/* ${STAGEDIR}${PREFIX}/www/mlmmj/perl-admin/templates
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/mlmmj/perl-admin/conf
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/perl-admin/conf/* ${STAGEDIR}${PREFIX}/www/mlmmj/perl-admin/conf
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/mlmmj/perl-user
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/web/perl-user/mlmmj.cgi ${STAGEDIR}${PREFIX}/www/mlmmj/perl-user
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/perl-user/config.pl ${STAGEDIR}${PREFIX}/www/mlmmj/perl-user
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/perl-user/example.html ${STAGEDIR}${PREFIX}/www/mlmmj/perl-user
.endif
.if defined(WITH_PHP_WEBINTERFACE)
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/mlmmj/php-user
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/php-user/* ${STAGEDIR}${PREFIX}/www/mlmmj/php-user
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/mlmmj/php-admin
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/php-admin/README ${STAGEDIR}${PREFIX}/www/mlmmj/php-admin
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/mlmmj/php-admin/htdocs
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/php-admin/htdocs/* ${STAGEDIR}${PREFIX}/www/mlmmj/php-admin/htdocs
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/mlmmj/php-admin/templates
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/php-admin/templates/* ${STAGEDIR}${PREFIX}/www/mlmmj/php-admin/templates
	@${MKDIR} ${STAGEDIR}${PREFIX}/www/mlmmj/php-admin/conf
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/php-admin/conf/* ${STAGEDIR}${PREFIX}/www/mlmmj/php-admin/conf
.endif

.include <bsd.port.post.mk>
