# ex:ts=8
# New ports collection makefile for:	p5-Frontier-RPC
# Date created:			Mar 8, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Frontier-RPC
PORTVERSION=	0.06
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://bitsko.slc.ut.us/~ken/xml-rpc/
MASTER_SITE_SUBDIR=	Frontier
PKGNAMEPREFIX=	p5-

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Frontier::RPC implements UserLand Software's XML RPC

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Frontier::Client.3 Frontier::Daemon.3 Frontier::RPC2.3

.include <bsd.port.mk>
