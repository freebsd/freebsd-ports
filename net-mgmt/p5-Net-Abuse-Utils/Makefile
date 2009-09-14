# New ports collection makefile for:	p5-Net-Abuse-Utils
# Date created:		2008-10-09
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Abuse-Utils
PORTVERSION=	0.11
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Routines useful for processing network abuse

RUN_DEPENDS=	p5-Email-Address>0:${PORTSDIR}/mail/p5-Email-Address \
		p5-Net-DNS>0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-Whois-IP>0:${PORTSDIR}/net/p5-Net-Whois-IP

PERL_CONFIGURE=	yes

MAN3=		Net::Abuse::Utils.3

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/examples/ip-info.pl ${PREFIX}/sbin/

.include <bsd.port.mk>
