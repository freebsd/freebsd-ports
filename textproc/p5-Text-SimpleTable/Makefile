# New ports collection makefile for:	p5-Text-SimpleTable
# Date created:		15 Nov 2005
# Whom:			Lars Balker Rasmussen <lars@balker.dk>
#
# $FreeBSD$
#

PORTNAME=	Text-SimpleTable
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/SR/SRI
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@balker.dk
COMMENT=	Simple Eyecandy ASCII Tables

PERL_MODBUILD=	yes

MAN3=		Text::SimpleTable.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' \
		${WRKSRC}/lib/Text/SimpleTable.pm
.endif
.include <bsd.port.post.mk>
