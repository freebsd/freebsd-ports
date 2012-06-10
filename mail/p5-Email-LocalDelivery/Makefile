# New ports collection makefile for:	p5-Email-LocalDelivery
# Date created:				August 31 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Email-LocalDelivery
PORTVERSION=	0.21.7
DISTVERSION=	${PORTVERSION:C/\.(.)$/\1/}
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Deliver a piece of email - simply

RUN_DEPENDS=	p5-Email-Simple>=0:${PORTSDIR}/mail/p5-Email-Simple \
		p5-Email-FolderType>=0:${PORTSDIR}/mail/p5-Email-FolderType \
		p5-File-Path-Expand>=0:${PORTSDIR}/devel/p5-File-Path-Expand
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::LocalDelivery.3

.include <bsd.port.mk>
