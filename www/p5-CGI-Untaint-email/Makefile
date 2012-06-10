# New ports collection makefile for:	CGI-Untaint-email
# Date created:	   17 August 2004
# Whom:		   Marc G. Fournier <scrappy@hub.org>
#
# $FreeBSD$
#

PORTNAME=	CGI-Untaint-email
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Validate an email address in a CGI form

RUN_DEPENDS=	p5-CGI-Untaint>=0:${PORTSDIR}/www/p5-CGI-Untaint \
		p5-Email-Valid>=0:${PORTSDIR}/mail/p5-Email-Valid \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		CGI::Untaint::email.3

.include <bsd.port.mk>
