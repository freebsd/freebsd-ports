# New ports collection makefile for:	p5-WWW-Shorten-NotLong
# Date created:				November 24 2009
# Whom:					Sahil Tandon <sahil@tandon.net>
#
# $FreeBSD$
#

PORTNAME=	WWW-Shorten-NotLong
PORTVERSION=	2.00
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sahil@FreeBSD.org
COMMENT=	A Perl interface to the web site notlong.com

BUILD_DEPENDS=	p5-libwww>=5.75:${PORTSDIR}/www/p5-libwww \
		p5-URI>=1.27:${PORTSDIR}/net/p5-URI \
		p5-WWW-Shorten>=0:${PORTSDIR}/www/p5-WWW-Shorten
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		WWW::Shorten::NotLong.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
