# New ports collection makefile for:	checkbot
# Version required:			1.51
# Date created:				2. Feb 1998
# Whom:	      				wosch@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	checkbot-1.54
CATEGORIES=	www perl5
MASTER_SITES=	http://www.xs4all.nl/~graaff/checkbot/ \
		http://www.de.freebsd.org/~wosch/src/

MAINTAINER=	wosch@FreeBSD.org

site_perl=${PREFIX}/lib/perl5/site_perl/${PERL_VER}
BUILD_DEPENDS=  \
		${site_perl}/${PERL_ARCH}/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${site_perl}/Mail/Send.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${site_perl}/LWP.pm:${PORTSDIR}/www/p5-libwww

MAN1=		checkbot.1
USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
		PREFIX=${PREFIX}

.include <bsd.port.mk>
