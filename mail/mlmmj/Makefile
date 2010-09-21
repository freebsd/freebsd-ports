# New ports collection makefile for:   mlmmj
# Date created:        12 june 2004
# Whom:                Christian Laursen <xi@borderworlds.dk>
#
# $FreeBSD$
#

PORTNAME=	mlmmj
PORTVERSION=	1.2.17.1
CATEGORIES=	mail
MASTER_SITES=	http://mlmmj.org/releases/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brix

MAINTAINER=	xi@borderworlds.dk
COMMENT=	Mailing list managing made joyful

LICENSE=	MIT

.if defined(WITH_PHP_WEBINTERFACE)
USE_PHP=	yes
WANT_PHP_WEB=	yes
.endif

.if defined(WITH_PERL_WEBINTERFACE)
RUN_DEPENDS+=	${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
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

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man
MAKE_JOBS_SAFE=	yes

MAN1=		mlmmj-bounce.1 mlmmj-list.1 mlmmj-maintd.1 mlmmj-make-ml.sh.1 mlmmj-process.1 mlmmj-recieve.1 mlmmj-send.1 mlmmj-sub.1 mlmmj-unsub.1

.include <bsd.port.pre.mk>

.if defined(WITH_PERL_WEBINTERFACE)
. if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
. endif
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/src/mlmmj-make-ml.sh

post-install:
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
	@${MKDIR} ${PREFIX}/www/mlmmj/php-admin
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/php-admin/README ${PREFIX}/www/mlmmj/php-admin
	@${MKDIR} ${PREFIX}/www/mlmmj/php-admin/htdocs
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/php-admin/htdocs/* ${PREFIX}/www/mlmmj/php-admin/htdocs
	@${MKDIR} ${PREFIX}/www/mlmmj/php-admin/templates
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/php-admin/templates/* ${PREFIX}/www/mlmmj/php-admin/templates
	@${MKDIR} ${PREFIX}/www/mlmmj/php-admin/conf
	@${INSTALL_DATA} ${WRKSRC}/contrib/web/php-admin/conf/* ${PREFIX}/www/mlmmj/php-admin/conf
.endif

.include <bsd.port.post.mk>
