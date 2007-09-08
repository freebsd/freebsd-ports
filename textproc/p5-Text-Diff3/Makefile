# New ports collection makefile for:	p5-Text-Diff3
# Date created:				29 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Diff3
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Compute three-way differences between texts

MAN3=	Text::Diff3.3 \
	Text::Diff3::Base.3 \
	Text::Diff3::Diff3.3 \
	Text::Diff3::DiffHeckel.3 \
	Text::Diff3::Factory.3 \
	Text::Diff3::List.3 \
	Text::Diff3::ListMixin.3 \
	Text::Diff3::Range2.3 \
	Text::Diff3::Range3.3 \
	Text::Diff3::Text.3

PERL_CONFIGURE=	yes

post-patch:
	@${RM} ${WRKSRC}/*.orig
	@${MKDIR} ${WRKSRC}/examples
	@${MV} ${WRKSRC}/*.pl ${WRKSRC}/examples

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
