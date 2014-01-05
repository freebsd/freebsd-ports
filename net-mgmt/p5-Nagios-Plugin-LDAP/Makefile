# Created by: Alexander Kriventsov <avk@vl.ru>
# $FreeBSD$

PORTNAME=	Nagios-Plugin-LDAP
PORTVERSION=	0.04
CATEGORIES=	net-mgmt
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	avk@vl.ru
COMMENT=	Nagios plugin to observe LDAP

USES=		perl5
USE_PERL5=	configure

BUILD_DEPENDS=	p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap \
		p5-Nagios-Plugin>=0:${PORTSDIR}/net-mgmt/p5-Nagios-Plugin \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime

RUN_DEPENDS:=	${BUILD_DEPENDS}

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
