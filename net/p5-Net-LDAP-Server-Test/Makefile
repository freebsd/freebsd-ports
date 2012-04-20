# New ports collection makefile for:	p5-Net-LDAP-Server-Test
# Date created:		2012-03-21
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-LDAP-Server-Test
PORTVERSION=	0.13
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
#MASTER_SITE_SUBDIR=	CPAN:KARMAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to test Net::LDAP code

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap \
		p5-Net-LDAP-Server>=0.3:${PORTSDIR}/net/p5-Net-LDAP-Server

PERL_CONFIGURE=	yes

MAN3=	Net::LDAP::Server::Test.3

.include <bsd.port.mk>
