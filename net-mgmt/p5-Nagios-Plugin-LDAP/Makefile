# New ports collection makefile for:	p5-Nagios-Plugin-LDAP
# Date created:		01 Mar 2011
# Whom:			Alexander Kriventsov <avk@vl.ru>
#
# $FreeBSD$
#

PORTNAME=	Nagios-Plugin-LDAP
PORTVERSION=	0.04
CATEGORIES=	net-mgmt
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	avk@vl.ru
COMMENT=	Nagios plugin to observe LDAP

PERL_CONFIGURE=	yes

BUILD_DEPENDS=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Nagios/Plugin.pm:${PORTSDIR}/net-mgmt/p5-Nagios-Plugin \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime

RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=		Nagios::Plugin::LDAP.3

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

.include <bsd.port.mk>
