# New ports collection makefile for:	mail/p5-Email-Folder-POP3
# Date created:				11 October 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Folder-POP3
PORTVERSION=	1.01.2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Email::Folder access to POP3 folders

RUN_DEPENDS=	p5-URI>=1.35:${PORTSDIR}/net/p5-URI \
		p5-Email-FolderType-Net>=1.02:${PORTSDIR}/mail/p5-Email-FolderType-Net \
		p5-Email-Folder>=0.84:${PORTSDIR}/mail/p5-Email-Folder \
		p5-Net>=1.19:${PORTSDIR}/net/p5-Net
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Email::Folder::POP3.3

.include <bsd.port.mk>
