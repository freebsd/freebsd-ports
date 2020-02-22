# Created by: erwin@FreeBSD.org
# $FreeBSD$

PORTNAME=	ResourcePool-Resource-Net-LDAP
PORTVERSION=	1.0003
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MWS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	ResourcePool wrapper for Net::LDAP

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-ResourcePool>=0:devel/p5-ResourcePool \
		p5-perl-ldap>=0:net/p5-perl-ldap

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
