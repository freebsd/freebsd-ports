# New ports collection makefile for:	CGI-SpeedyCGI
# Date created:				Sun Mar 10 16:44:06 CET 2002
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	CGI-SpeedyCGI
PORTVERSION=	2.22
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Speed up perl CGI scripts by running them persistently

PERL_CONFIGURE=	yes

OPTIONS=	APACHE "Enable mod_speedycgi" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_APACHE)
USE_APACHE=	1.3+
PLIST_SUB+=	APACHE=""
.else
PLIST_SUB+=	APACHE="@comment "
CONFIGURE_ENV+=	WITHOUT_APACHE=yes
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
