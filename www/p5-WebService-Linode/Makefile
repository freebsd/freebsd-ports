# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	WebService-Linode
PORTVERSION=	0.11
CATEGORIES=	www
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	WebService
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Interface to the Linode.com API

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Crypt-SSLeay>0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-JSON>0:${PORTSDIR}/converters/p5-JSON \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww

USES=		perl5
USE_PERL5=	configure

MAN3=		WebService::Linode.3 \
		WebService::Linode::Base.3 \
		WebService::Linode::DNS.3

.include <bsd.port.mk>
