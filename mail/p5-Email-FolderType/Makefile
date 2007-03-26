# New ports collection makefile for:	p5-Email-FolderType
# Date created:				August 31 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Email-FolderType
PORTVERSION=	0.8.13
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-0.813

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Determine the type of a mail folder

RUN_DEPENDS=	p5-Module-Pluggable>0:${PORTSDIR}/devel/p5-Module-Pluggable
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::FolderType.3 \
		Email::FolderType::Ezmlm.3 \
		Email::FolderType::MH.3 \
		Email::FolderType::Maildir.3 \
		Email::FolderType::Mbox.3

.include <bsd.port.mk>
