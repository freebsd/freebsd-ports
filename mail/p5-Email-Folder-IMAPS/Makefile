# New ports collection makefile for:	mail/p5-Email-Folder-IMAPS
# Date created:				30 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Folder-IMAPS
PORTVERSION=	1.04
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Email::Folder access to IMAP over SSL folders

BUILD_DEPENDS=	${SITE_PERL}/URI/imaps.pm:${PORTSDIR}/mail/p5-URI-imaps \
		${SITE_PERL}/Email/Folder/IMAP.pm:${PORTSDIR}/mail/p5-Email-Folder-IMAP \
		${SITE_PERL}/Email/FolderType/Net.pm:${PORTSDIR}/mail/p5-Email-FolderType-Net \
		${SITE_PERL}/Net/IMAP/Simple/SSL.pm:${PORTSDIR}/mail/p5-Net-IMAP-Simple-SSL
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Email::Folder::IMAPS.3

.include <bsd.port.mk>
