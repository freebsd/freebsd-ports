# New ports collection makefile for:	p5-Net-Netmask
# Date created:				Jan 28 2000
# Whom:					Wei-chun Chao
#
# $FreeBSD$
#

PORTNAME=	Net-Netmask
PORTVERSION=	1.9004
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to parse, manipulate and lookup IP network blocks

PERL_CONFIGURE=	yes

MAN3=		Net::Netmask.3

post-patch:
	@${PERL} -pi -e '$$_ = "" if $$. == 1' ${WRKSRC}/Netmask.pm

.include <bsd.port.mk>
