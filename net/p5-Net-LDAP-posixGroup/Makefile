# New ports collection makefile for:	sysutils/p5-Net-LDAP-posixGroup
# Date created:		2009-10-31
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Net-LDAP-posixGroup
PORTVERSION=	0.0.1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Creates new Net::LDAP::Entry objects for a posixGroup entry

RUN_DEPENDS=	${SITE_PERL}/Net/LDAP/Entry.pm:${PORTSDIR}/net/p5-perl-ldap

PERL_CONFIGURE=	yes

MAN3=		Net::LDAP::posixGroup.3

.include <bsd.port.mk>
