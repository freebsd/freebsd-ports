# New ports collection makefile for:	checkbot
# Date created:				2. Feb 1998
# Whom:	      				wosch@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	checkbot
PORTVERSION=	1.62
CATEGORIES=	www perl5
MASTER_SITES=	http://degraaff.org/checkbot/ \
		http://www.de.freebsd.org/~wosch/src/

MAINTAINER=	wosch@FreeBSD.org

SITE_PERL=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}

BUILD_DEPENDS=  	\
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
 		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net \
		${SITE_PERL}/Mail/Send.pm:${PORTSDIR}/mail/p5-Mail-Tools \

RUN_DEPENDS=    ${BUILD_DEPENDS}

MAN1=		checkbot.1
USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
		PREFIX=${PREFIX}

.include <bsd.port.mk>
