# New ports collection makefile for:	p5-Net-LDAP-Server
# Date created:		2nd Oct, 2009
# Whom:			Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-LDAP-Server
PORTVERSION=	0.42
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Perl module for LDAP server side protocol handling

BUILD_DEPENDS=	p5-Convert-ASN1>=0.22:${PORTSDIR}/converters/p5-Convert-ASN1 \
		p5-perl-ldap>=0.39:${PORTSDIR}/net/p5-perl-ldap
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::LDAP::Server.3

.include <bsd.port.mk>
