# New ports collection makefile for:	mail/p5-Email-Find
# Date created:				28 December 2000
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Find
PORTVERSION=	0.02
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@tobez.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Email/Valid.pm:${PORTSDIR}/mail/p5-Email-Valid

PERL_CONFIGURE=	yes

MAN3=		Email::Find.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
