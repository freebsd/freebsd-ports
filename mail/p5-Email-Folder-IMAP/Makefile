# New ports collection makefile for:	mail/p5-Email-Folder-IMAP
# Date created:				30 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Folder-IMAP
PORTVERSION=	1.02
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Email::Folder Access to IMAP Folders

BUILD_DEPENDS=	${SITE_PERL}/Email/Folder/Reader.pm:${PORTSDIR}/mail/p5-Email-Folder \
		${SITE_PERL}/Email/FolderType/Net.pm:${PORTSDIR}/mail/p5-Email-FolderType-Net \
		${SITE_PERL}/URI/imap.pm:${PORTSDIR}/mail/p5-URI-imap
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Email::Folder::IMAP.3

.include <bsd.port.mk>
