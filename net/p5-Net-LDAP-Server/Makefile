# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-LDAP-Server
PORTVERSION=	0.43
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Perl module for LDAP server side protocol handling

BUILD_DEPENDS=	p5-Convert-ASN1>=0.22:converters/p5-Convert-ASN1 \
		p5-perl-ldap>=0.39:net/p5-perl-ldap
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
