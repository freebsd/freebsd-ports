# New ports collection makefile for:	mail/p5-Email-Delete
# Date created:				31 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Delete
PORTVERSION=	1.02
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Delete Messages from Folders

BUILD_DEPENDS=	${SITE_PERL}/File/Find/Rule.pm:${PORTSDIR}/devel/p5-File-Find-Rule \
		${SITE_PERL}/Email/Folder.pm:${PORTSDIR}/mail/p5-Email-Folder \
		${SITE_PERL}/Email/Simple.pm:${PORTSDIR}/mail/p5-Email-Simple \
		${SITE_PERL}/Email/LocalDelivery.pm:${PORTSDIR}/mail/p5-Email-LocalDelivery \
		${SITE_PERL}/Email/FolderType.pm:${PORTSDIR}/mail/p5-Email-FolderType
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Email::Delete.3 \
	Email::Delete::Maildir.3 \
	Email::Delete::Mbox.3

.include <bsd.port.mk>
