# ports collection makefile for: spampd
# Date created: 7 April 2004
# Whom: chris
#
# $FreeBSD$
#

PORTNAME=	spampd
PORTVERSION=	2.30
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	http://www.worlddesign.com/Content/rd/mta/spampd/

MAINTAINER=	christian.schade@interface-systems.de
COMMENT=	Spamassassin SMTP Proxy

RUN_DEPENDS=	spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin \
		${SITE_PERL}/Net/Server/PreForkSimple.pm:${PORTSDIR}/net/p5-Net-Server

NO_BUILD=	yes
PLIST_FILES=	sbin/spampd
USE_PERL5=	yes
USE_RC_SUBR=	spampd

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/spampd ${PREFIX}/sbin

.include <bsd.port.mk>
