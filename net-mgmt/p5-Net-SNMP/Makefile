# New ports collection makefile for:	p5-Net-SNMP
# Date created:				30 June 2000
# Whom:					Christopher N. Harrell <cnh@ivmg.net>
#
# $FreeBSD$
#

PORTNAME=	Net-SNMP
PORTVERSION=	4.1.0
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@thegler.dk
COMMENT=	A perl module for SNMP... Net::SNMP

.include <bsd.port.pre.mk>

RUN_DEPENDS=	${ARCH_PERL}/Crypt/DES.pm:${PORTSDIR}/security/p5-Crypt-DES \
		${ARCH_PERL}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${ARCH_PERL}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/Digest/HMAC.pm:${PORTSDIR}/security/p5-Digest-HMAC

PERL_CONFIGURE=	yes
ARCH_PERL=	${SITE_PERL}/${PERL_ARCH}

.if ${PERL_LEVEL} < 500600
IGNORE=         Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

MAN1=		snmpkey.1
MAN3=		Net::SNMP.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.post.mk>
