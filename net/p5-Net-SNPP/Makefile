# New ports collection makefile for:	Net-SNPP
# Date created:		6 Jun 2002
# Whom:			devin@spamcop.net
#
# $FreeBSD$
#

PORTNAME=	Net-SNPP
PORTVERSION=	1.13
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/Cmd.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::SNPP.3

.include <bsd.port.mk>
