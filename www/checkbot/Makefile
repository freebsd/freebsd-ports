# New ports collection makefile for:	checkbot
# Version required:			1.51
# Date created:				2. Feb 1998
# Whom:	      				wosch@FreeBSD.org
#
# $Id: Makefile,v 1.5 1998/09/15 21:31:54 asami Exp $
#

DISTNAME=	checkbot-1.51
CATEGORIES=	www perl5
MASTER_SITES=	http://www.xs4all.nl/~graaff/checkbot/

MAINTAINER=	wosch@FreeBSD.ORG

BROKEN=		manpage gets installed in /usr/share/ in -current

site_perl=${PREFIX}/lib/perl5/site_perl
BUILD_DEPENDS=  \
		${site_perl}/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${site_perl}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${site_perl}/Mail/Send.pm:${PORTSDIR}/mail/p5-Mail-Tools

MAN1=		checkbot.1
USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
