# New ports collection makefile for:	p5-Email-MIME-ContentType
# Date created:				2004-08-29
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Email-MIME-ContentType
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Email
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Parse a MIME Content-Type Header

PERL_CONFIGURE=	yes

MAN3=		Email::MIME::ContentType.3

.include <bsd.port.pre.mk>
post-patch:
	${PERL} -pi -e '$$_ = "" if /use 5.006;/;' \
		${WRKSRC}/Makefile.PL
	${PERL} -pi -e '$$_ = "" if /require 5.006;/;' \
		    -e '$$_ = "" if /use warnings/;' \
		    -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' \
		${WRKSRC}/ContentType.pm
.include <bsd.port.post.mk>
