# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Jifty-Plugin-Authentication-Ldap
PORTVERSION=	1.01
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	LDAP Authentication Plugin for Jifty Apps

BROKEN=		Fails to configure

BUILD_DEPENDS=	p5-Jifty>=0:${PORTSDIR}/www/p5-Jifty \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
