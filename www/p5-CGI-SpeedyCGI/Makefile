# New ports collection makefile for:	CGI-SpeedyCGI
# Date created:				Sun Mar 10 16:44:06 CET 2002
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	CGI-SpeedyCGI
PORTVERSION=	2.22
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Speed up perl CGI scripts by running them persistently

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

# define WITHOUT_APACHE to prevent mod_speedycgi from being built even if Apache is installed

.if !exists(${APXS}) || defined(WITHOUT_APACHE)
PLIST_SUB+=	APACHE="@comment "
CONFIGURE_ENV+=	WITHOUT_APACHE=yes
.else
PLIST_SUB+=	APACHE=""
.if exists(${APXS})
APXS_WORKS!=	${APXS} -q TARGET 2>/dev/null || ${ECHO} no
.endif
.if exists(${APXS}) && ${APXS_WORKS} != no
AP_LIBEXEC!=	${APXS} -q LIBEXECDIR
.else
AP_LIBEXEC?=	${PREFIX}/libexec/apache
.endif
PLIST_SUB+=	AP_LIBEXEC=${AP_LIBEXEC:S/^${PREFIX}\///}
.endif

post-patch:
	@${PERL} -pi -e 's,apxs -q,${APXS} -q,;' \
		${WRKSRC}/src/SpeedyMake.pl
	@${PERL} -pi -e 's,APXS=apxs,APXS=${APXS},;' \
		${WRKSRC}/mod_speedycgi/Makefile.tmpl

post-configure:
	@${PERL} -pi -e 's,^PREFIX = /usr$$,PREFIX = ${PREFIX},g;' \
		${WRKSRC}/Makefile ${WRKSRC}/*/Makefile

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/speedy/speedy ${PREFIX}/bin/speedy_suidperl
	@${CHMOD} 4755 ${PREFIX}/bin/speedy_suidperl

.include <bsd.port.post.mk>
