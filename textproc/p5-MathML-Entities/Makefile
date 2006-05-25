# New ports collection makefile for:	p5-MathML-Entities
# Date created:				25 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MathML-Entities
PORTVERSION=	0.13
CATEGORIES=	textproc www math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MathML
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Convert XHTML+MathML Named Entities to Numeric Character References

MAN3=	MathML::Entities.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our (\S+)/use vars qw{$$1};$$1/g' \
		${WRKSRC}/lib/MathML/Entities.pm
.endif

.include <bsd.port.post.mk>
