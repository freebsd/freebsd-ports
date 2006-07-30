# New ports collection makefile for:	mail/p5-Email-Folder-IMAP
# Date created:				30 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Folder-IMAP
PORTVERSION=	1.10
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Email::Folder Access to IMAP Folders

BUILD_DEPENDS=	p5-Email-FolderType-Net>=0:${PORTSDIR}/mail/p5-Email-FolderType-Net \
		p5-Email-Folder>=0:${PORTSDIR}/mail/p5-Email-Folder \
		p5-Net-IMAP-Simple>=0.95:${PORTSDIR}/mail/p5-Net-IMAP-Simple \
		p5-URI-imap>=0:${PORTSDIR}/mail/p5-URI-imap
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Email::Folder::IMAP.3

.include <bsd.port.mk>
