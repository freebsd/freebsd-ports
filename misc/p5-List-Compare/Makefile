# New ports collection makefile for:	p5-List-Compare
# Date created:				23 Oct 2004
# Whom:					Dmitry Morozovsky <marck@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		List-Compare
PORTVERSION=	0.37
CATEGORIES=		misc perl5
MASTER_SITES=		CPAN
PKGNAMEPREFIX=		p5-

MAINTAINER=		marck@FreeBSD.org
COMMENT=		Perl extension for comparing lists

PERL_CONFIGURE=		yes

PLIST_FILES=	\
	${SITE_PERL_REL}/List/Compare.pm \
	${SITE_PERL_REL}/List/Compare/Base/_Auxiliary.pm \
	${SITE_PERL_REL}/List/Compare/Base/_Engine.pm \
	${SITE_PERL_REL}/List/Compare/Functional.pm \
	${SITE_PERL_REL}/${PERL_ARCH}/auto/List/Compare/.packlist
PLIST_DIRS+=	\
	${SITE_PERL_REL}/List/Compare/Base \
	${SITE_PERL_REL}/List/Compare \
	${SITE_PERL_REL}/List \
	${SITE_PERL_REL}/${PERL_ARCH}/auto/List/Compare \
	${SITE_PERL_REL}/${PERL_ARCH}/auto/List

MAN3=			List::Compare.3 \
			List::Compare::Base::_Auxiliary.3 \
			List::Compare::Base::_Engine.3 \
			List::Compare::Functional.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
