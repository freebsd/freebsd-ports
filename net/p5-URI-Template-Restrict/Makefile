# New ports collection makefile for:	URI::Template::Restrict
# Date created:		22 Jan 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	URI-Template-Restrict
PORTVERSION=	0.06
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for restricted URI Templates handler

RUN_DEPENDS=	\
	p5-List-MoreUtils>0:${PORTSDIR}/lang/p5-List-MoreUtils \
	p5-Unicode-Normalize>0:${PORTSDIR}/textproc/p5-Unicode-Normalize \
	p5-URI>0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	\
	p5-URI>0:${PORTSDIR}/net/p5-URI

PERL_CONFIGURE=	yes

MAN3=		URI::Template::Restrict.3 \
		URI::Template::Restrict::Expansion.3

.include <bsd.port.mk>
