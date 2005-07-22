# New ports collection makefile for:	p5-Net-SNMP
# Date created:				30 June 2000
# Whom:					Christopher N. Harrell <cnh@ivmg.net>
#
# $FreeBSD$
#

PORTNAME=	Net-SNMP
PORTVERSION=	5.1.0
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A perl module for SNMP... Net::SNMP

BUILD_DEPENDS=	${ARCH_PERL}/Crypt/DES.pm:${PORTSDIR}/security/p5-Crypt-DES \
		${ARCH_PERL}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/Digest/HMAC.pm:${PORTSDIR}/security/p5-Digest-HMAC
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
ARCH_PERL=	${SITE_PERL}/${PERL_ARCH}
CONFLICTS=	p5-Net-SNMP3-[0-9]*

MAN1=		snmpkey.1
MAN3=		Net::SNMP.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif
.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${ARCH_PERL}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
.endif

.include <bsd.port.post.mk>
