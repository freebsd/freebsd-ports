# New ports collection makefile for:	security/p5-GSSAPI
# Date created:				28 March 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GSSAPI
PORTVERSION=	0.20
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/A/AG/AGROLMS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	GSSAPI - Perl extension providing access to the GSSAPIv2 library

PERL_CONFIGURE=	yes

MAN3=	GSSAPI.3 \
	GSSAPI::OID.3 \
	GSSAPI::OID::Set.3 \
	GSSAPI::Status.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
