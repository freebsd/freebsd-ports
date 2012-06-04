# New ports collection makefile for:	Authen-Simple-SMB
# Date created:				22 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Authen-Simple-SMB
PORTVERSION=	0.1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple SMB authentication

BUILD_DEPENDS=	p5-Authen-Simple>=0:${PORTSDIR}/security/p5-Authen-Simple \
		p5-Authen-Smb>=0:${PORTSDIR}/security/p5-Authen-Smb
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Authen::Simple::SMB.3

PERL_MODBUILD=	yes

.include <bsd.port.mk>
