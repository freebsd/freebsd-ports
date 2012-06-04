# New ports collection makefile for:	Authen-Simple-PAM
# Date created:				22 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Authen-Simple-PAM
PORTVERSION=	0.2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple PAM authentication

BUILD_DEPENDS=	p5-Authen-Simple>=0:${PORTSDIR}/security/p5-Authen-Simple \
		p5-Authen-PAM>=0:${PORTSDIR}/security/p5-Authen-PAM
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Authen::Simple::PAM.3

PERL_MODBUILD=	yes

.include <bsd.port.mk>
