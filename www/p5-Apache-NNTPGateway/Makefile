# New ports collection makefile for:	Apache::NNTPGateway
# Date created:		15 Jan 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-NNTPGateway
PORTVERSION=	0.9
CATEGORIES=	www news perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	A NNTP interface for mod_perl enabled Apache web server

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/NNTPGateway-${PORTVERSION}

PERL_CONFIGURE=	yes

MAN3=		Apache::NNTPGateway.3

.include <bsd.port.mk>
