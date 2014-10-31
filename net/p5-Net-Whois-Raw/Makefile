# Created by: Alex Kapranoff <kappa@FreeBSD.org.ua>
# $FreeBSD$

PORTNAME=	Net-Whois-Raw
PORTVERSION=	2.79
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NALOBIN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Very simple Perl interface to query raw whois data

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-Net-IDN-Encode>=1:${PORTSDIR}/textproc/p5-Net-IDN-Encode \
		p5-Regexp-IPv6>=0:${PORTSDIR}/textproc/p5-Regexp-IPv6 \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
