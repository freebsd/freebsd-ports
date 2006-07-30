# New ports collection makefile for:	mail/p5-Email-Folder-IMAPS
# Date created:				30 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Folder-IMAPS
PORTVERSION=	1.10
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Email::Folder access to IMAP over SSL folders

BUILD_DEPENDS=	p5-Email-FolderType-Net>=0:${PORTSDIR}/mail/p5-Email-FolderType-Net \
		p5-Email-Folder-IMAP>=0:${PORTSDIR}/mail/p5-Email-Folder-IMAP \
		p5-Net-IMAP-Simple-SSL>=1.3:${PORTSDIR}/mail/p5-Net-IMAP-Simple-SSL \
		p5-URI-imaps>=0:${PORTSDIR}/mail/p5-URI-imaps
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Email::Folder::IMAPS.3

.include <bsd.port.mk>
