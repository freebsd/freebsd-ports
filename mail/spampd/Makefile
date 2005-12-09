# ports collection makefile for: spampd
# Date created: 7 April 2004
# Whom: chris
#
# $FreeBSD$
#

PORTNAME=	spampd
PORTVERSION=	2.30
CATEGORIES=	mail perl5
MASTER_SITES=	http://www.worlddesign.com/Content/rd/mta/spampd/

MAINTAINER=	christian.schade@interface-systems.de
COMMENT=	Spamassassin SMTP Proxy

RUN_DEPENDS=	spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin \
		${SITE_PERL}/Net/Server/PreForkSimple.pm:${PORTSDIR}/net/p5-Net-Server

NO_BUILD=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/spampd ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${FILESDIR}/spampd.sh.sample ${PREFIX}/etc/rc.d

.include <bsd.port.pre.mk>

# spampd -> p5-Mail-SpamAssassin
.if ${PERL_LEVEL} < 500601
IGNORE=		needs perl 5.6.1 or higher, install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
