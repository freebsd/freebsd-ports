# Created by: Marc G. Fournier
# $FreeBSD$

PORTNAME=	Maypole-Authentication-UserSessionCookie
PORTVERSION=	1.4
PORTREVISION=	0
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SIMON
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Track sessions and, optionally, users

USES=		perl5
USE_PERL5=	configure patch

MAN3=		Maypole::Authentication::UserSessionCookie.3

post-patch:
	@${PERL} -pi -e 's/^our (\S+)/use vars qw($$1); $$1/' ${WRKSRC}/UserSessionCookie.pm

.include <bsd.port.mk>
