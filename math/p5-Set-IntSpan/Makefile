# New ports collection makefile for:	p5-Set-IntSpan
# Date created:		February 7, 1998
# Whom:			Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	Set-IntSpan
PORTVERSION=	1.08
PORTREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Set
PKGNAMEPREFIX=	p5-

MAINTAINER=	croyle@gelemna.org
COMMENT=	Manages sets of integers

PERL_CONFIGURE=	yes

MAN3=		Set::IntSpan.3

post-patch:
	@${REINPLACE_CMD} -e 's|^our ||g' ${WRKSRC}/IntSpan.pm
	@${REINPLACE_CMD} -Ee 's/(^use base.*)/\1 use vars qw(@EXPORT_OK $$VERSION);/' \
		${WRKSRC}/IntSpan.pm

.include <bsd.port.mk>
