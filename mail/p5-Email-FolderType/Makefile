# New ports collection makefile for:	p5-Email-FolderType
# Date created:				August 31 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Email-FolderType
PORTVERSION=	0.6
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@thegler.dk
COMMENT=	Determine the type of a mail folder

PERL_CONFIGURE=	yes

MAN3=		Email::FolderType.3

test:
	cd ${WRKSRC} ; make test

.include <bsd.port.mk>
