# New ports collection makefile for:   p5-Catalyst-View-Email
# Date created:          2007-06-04
# Whom:                     Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-Email
PORTVERSION=	0.31
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst View for Email

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.00:${PORTSDIR}/www/p5-Catalyst-Devel \
		p5-Catalyst-View-TT>0:${PORTSDIR}/www/p5-Catalyst-View-TT \
		p5-Catalyst-View-Mason>0:${PORTSDIR}/www/p5-Catalyst-View-Mason \
		p5-Class-C3>=0:${PORTSDIR}/devel/p5-Class-C3 \
		p5-Email-MIME>=1.859:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Email-Sender>=0.100110:${PORTSDIR}/mail/p5-Email-Sender \
		p5-parent>0:${PORTSDIR}/devel/p5-parent \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Helper::View::Email.3 \
	Catalyst::Helper::View::Email::Template.3 \
	Catalyst::View::Email.3 \
	Catalyst::View::Email::Template.3

.include <bsd.port.mk>
