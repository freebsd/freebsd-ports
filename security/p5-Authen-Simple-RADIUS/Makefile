# New ports collection makefile for:	Authen-Simple-RADIUS
# Date created:				22 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Authen-Simple-RADIUS
PORTVERSION=	0.1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple RADIUS authentication

BUILD_DEPENDS=	p5-Authen-Simple>=0:${PORTSDIR}/security/p5-Authen-Simple \
		p5-Authen-Radius>=0:${PORTSDIR}/security/p5-Authen-Radius
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Authen::Simple::RADIUS.3

PERL_MODBUILD=	yes

.include <bsd.port.mk>
