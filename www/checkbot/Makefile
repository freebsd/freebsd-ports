# New ports collection makefile for:	checkbot
# Date created:				2. Feb 1998
# Whom:	      				wosch@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	checkbot
PORTVERSION= 	1.58
CATEGORIES=	www perl5
MASTER_SITES=	http://www.xs4all.nl/~graaff/checkbot/ \
		http://www.de.freebsd.org/~wosch/src/

MAINTAINER=	wosch@FreeBSD.org

BUILD_DEPENDS=  ${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/Mail/Send.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI

SITE_PERL=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}
FETCH_BEFORE_ARGS=	-b

MAN1=		checkbot.1
USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
		PREFIX=${PREFIX}

.include <bsd.port.mk>
