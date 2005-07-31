# New ports collection makefile for:	p5-Maypole-Authentication-UserSessionCookie
# Date created:				Aug 21 2004
# Whom:					Marc G. Fournier
#
# $FreeBSD$

PORTNAME=	Maypole-Authentication-UserSessionCookie
PORTVERSION=	1.4
PORTREVISION=	0
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/SI/SIMON/
PKGNAMEPREFIX=	p5-

MAINTAINER=	scrappy@FreeBSD.org
COMMENT=	Track sessions and, optionally, users

PERL_CONFIGURE=	yes

MAN3=		Maypole::Authentication::UserSessionCookie.3

post-patch:
	@${PERL} -pi -e 's/^our (\S+)/use vars qw($$1); $$1/' ${WRKSRC}/UserSessionCookie.pm

.include <bsd.port.mk>
