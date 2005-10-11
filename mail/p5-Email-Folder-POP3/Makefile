# New ports collection makefile for:	mail/p5-Email-Folder-POP3
# Date created:				11 October 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Folder-POP3
PORTVERSION=	1.01
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Email::Folder access to POP3 folders

BUILD_DEPENDS=	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Email/FolderType/Net.pm:${PORTSDIR}/mail/p5-Email-FolderType-Net \
		${SITE_PERL}/Email/Folder.pm:${PORTSDIR}/mail/p5-Email-Folder \
		${SITE_PERL}/Net/POP3.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Email::Folder::POP3.3

.include <bsd.port.mk>
