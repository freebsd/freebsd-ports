# New ports collection makefile for:	mail/p5-Email-Delete
# Date created:				31 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Email-Delete
PORTVERSION=	1.02.2
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C|\.([0-9])$|\1|}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Delete Messages from Folders

RUN_DEPENDS=	p5-Email-Folder>=0.84:${PORTSDIR}/mail/p5-Email-Folder \
		p5-Email-FolderType>=0.7:${PORTSDIR}/mail/p5-Email-FolderType \
		p5-Email-LocalDelivery>=0.21.3:${PORTSDIR}/mail/p5-Email-LocalDelivery \
		p5-Email-Simple>=1.92:${PORTSDIR}/mail/p5-Email-Simple \
		p5-File-Find-Rule>=0.28:${PORTSDIR}/devel/p5-File-Find-Rule
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Email::Delete.3 \
	Email::Delete::Maildir.3 \
	Email::Delete::Mbox.3

.include <bsd.port.mk>
