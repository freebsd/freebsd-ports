# New ports collection makefile for:	p5-Email-Folder
# Date created:				August 31 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Email-Folder
PORTVERSION=	0.84
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Read all the messages from a folder as Email::Simple objects

BUILD_DEPENDS=	${SITE_PERL}/Email/Simple.pm:${PORTSDIR}/mail/p5-Email-Simple \
		${SITE_PERL}/Email/FolderType.pm:${PORTSDIR}/mail/p5-Email-FolderType
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Email::Folder.3 \
		Email::Folder::MH.3 \
		Email::Folder::Maildir.3 \
		Email::Folder::Mbox.3 \
		Email::Folder::Reader.3

.include <bsd.port.mk>
