# New ports collection makefile for:	p5-Email-LocalDelivery-Ezmlm
# Date created:				September 7 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Email-LocalDelivery-Ezmlm
PORTVERSION=	0.10
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Deliver mail into ezmlm archives

BUILD_DEPENDS=	${SITE_PERL}/Email/LocalDelivery.pm:${PORTSDIR}/mail/p5-Email-LocalDelivery \
		${SITE_PERL}/Email/FolderType.pm:${PORTSDIR}/mail/p5-Email-FolderType
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Email::LocalDelivery::Ezmlm.3

post-patch:
		@${RM} ${WRKSRC}/lib/Email/LocalDelivery/Ezmlm.pm.orig
test:
	cd ${WRKSRC} ; make test

.include <bsd.port.mk>
