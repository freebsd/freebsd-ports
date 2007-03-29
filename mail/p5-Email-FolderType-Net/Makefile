# New ports collection makefile for:	mail/p5-Email-FolderType-Net
# Date created:				30 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-FolderType-Net
PORTVERSION=	1.04.1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Recognize folder types for network based message protocols

RUN_DEPENDS=	p5-URI>=1.35:${PORTSDIR}/net/p5-URI \
		p5-Email-FolderType>=0.8:${PORTSDIR}/mail/p5-Email-FolderType
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Email::FolderType::Net.3

.include <bsd.port.mk>
