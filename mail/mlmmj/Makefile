# New ports collection makefile for:   mlmmj
# Date created:        12 june 2004
# Whom:                Christian Laursen <xi@borderworlds.dk>
#
# $FreeBSD$
#

PORTNAME=	mlmmj
PORTVERSION=	1.0.0.r2
CATEGORIES=	mail
MASTER_SITES=	http://mlmmj.mmj.dk/files/
DISTNAME=	mlmmj-1.0.0-RC2

MAINTAINER=	xi@borderworlds.dk
COMMENT=	Mailing list managing made joyful

.if defined(WITH_PHP_WEBINTERFACE)
USE_PHP=        yes
WANT_PHP_WEB=   yes
.endif

.if defined(WITH_PERL_WEBINTERFACE)
RUN_DEPENDS+=	${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/CGI/FastTemplate.pm:${PORTSDIR}/www/p5-CGI-FastTemplate
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

USE_BZIP2=	yes
USE_REINPLACE=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/src/mlmmj-make-ml.sh

post-install:
	@${MKDIR} ${PREFIX}/share/mlmmj/listtexts
	@${INSTALL_DATA} ${WRKSRC}/listtexts/* ${PREFIX}/share/mlmmj/listtexts
.if defined(WITH_PERL_WEBINTERFACE)
	@${MKDIR} ${PREFIX}/www/mlmmj/perl-admin
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/perl-admin/README ${PREFIX}/www/mlmmj/perl-admin
	@${MKDIR} ${PREFIX}/www/mlmmj/perl-admin/htdocs
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/web/perl-admin/htdocs/* ${PREFIX}/www/mlmmj/perl-admin/htdocs
	@${MKDIR} ${PREFIX}/www/mlmmj/perl-admin/templates
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/perl-admin/templates/* ${PREFIX}/www/mlmmj/perl-admin/templates
	@${MKDIR} ${PREFIX}/www/mlmmj/perl-admin/conf
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/perl-admin/conf/* ${PREFIX}/www/mlmmj/perl-admin/conf
	@${MKDIR} ${PREFIX}/www/mlmmj/perl-user
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/web/perl-user/mlmmj.cgi ${PREFIX}/www/mlmmj/perl-user
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/perl-user/config.pl ${PREFIX}/www/mlmmj/perl-user
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/perl-user/example.html ${PREFIX}/www/mlmmj/perl-user
.endif
.if defined(WITH_PHP_WEBINTERFACE)
	@${MKDIR} ${PREFIX}/www/mlmmj/php-user
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/php-user/* ${PREFIX}/www/mlmmj/php-user
.endif

.include <bsd.port.mk>
