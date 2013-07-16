# $FreeBSD$

PORTNAME=	Dancer-Plugin-Email
PORTVERSION=	1.0100
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:IRONCAMEL
PKGNAMEPREFIX=	p5-

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Simple email handling for Dancer applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Dancer>=1.2:${PORTSDIR}/www/p5-Dancer \
		p5-Email-Sender>=0:${PORTSDIR}/mail/p5-Email-Sender \
		p5-File-Type>=0:${PORTSDIR}/devel/p5-File-Type \
		p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Dancer::Plugin::Email.3

.include <bsd.port.mk>
