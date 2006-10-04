# New ports collection makefile for:	Net-SDP
# Date created:	   17 June 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Net-SDP
PORTVERSION=	0.07
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Session Description Protocol (RFC 2327) packet parser/generator

BUILD_DEPENDS=	${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN1=		sdp2rat.1
MAN3=		Net::SDP.3 Net::SDP::Media.3 Net::SDP::Time.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600 # inherited from p5-libwww
IGNORE=	requires at least Perl 5.6.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
