# New ports collection makefile for:	p5-Email-MIME-ContentType
# Date created:				2004-08-29
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Email-MIME-ContentType
PORTVERSION=	1.0
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Parse a MIME Content-Type Header

PERL_CONFIGURE=	yes

MAN3=		Email::MIME::ContentType.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
EXTRA_PATCHES=	${PATCHDIR}/5.005_03-*
.endif
.include <bsd.port.post.mk>
