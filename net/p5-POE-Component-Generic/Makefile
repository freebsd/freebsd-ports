# New ports collection makefile for:	p5-POE-Component-Generic
# Date created:		2006-08-30
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Generic
PORTVERSION=	0.09.10
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Provides non-blocking access to a blocking object

RUN_DEPENDS=	p5-POE>=0.31:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/Devel/Symdump.pm:${PORTSDIR}/devel/p5-Devel-Symdump
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	POE::Component::Generic.3 \
		POE::Component::Generic::Child.3 \
		POE::Component::Generic::Net::SSH2.3 \
		POE::Component::Generic::Object.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500702
IGNORE=	requires perl 5.7.2 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
