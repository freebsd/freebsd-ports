# New ports collection makefile for:	p5-Maypole
# Date created:				Apr 2 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Maypole
PORTVERSION=	1.4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/SI/SIMON/
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	MVC web application framework

BUILD_DEPENDS=	${SITE_PERL}/Class/DBI/Loader.pm:${PORTSDIR}/databases/p5-Class-DBI-Loader \
		${SITE_PERL}/Class/DBI/AbstractSearch.pm:${PORTSDIR}/databases/p5-Class-DBI-AbstractSearch \
		${SITE_PERL}/Class/DBI/Pager.pm:${PORTSDIR}/databases/p5-Class-DBI-Pager \
		${SITE_PERL}/Class/DBI/Plugin/RetrieveAll.pm:${PORTSDIR}/databases/p5-Class-DBI-Plugin-RetrieveAll \
		${SITE_PERL}/Class/DBI/AsForm.pm:${PORTSDIR}/databases/p5-Class-DBI-AsForm \
		${SITE_PERL}/Class/DBI/FromCGI.pm:${PORTSDIR}/databases/p5-Class-DBI-FromCGI \
		${SITE_PERL}/Class/DBI/Loader/Relationship.pm:${PORTSDIR}/databases/p5-Class-DBI-Loader-Relationship \
		${SITE_PERL}/CGI/Untaint.pm:${PORTSDIR}/www/p5-CGI-Untaint \
		${SITE_PERL}/UNIVERSAL/moniker.pm:${PORTSDIR}/devel/p5-UNIVERSAL-moniker \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-exports \
		${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGMSG_SUB=	DOCSDIR=${DOCSDIR} \
		DATADIR=${DATADIR} \
		EXAMPLESDIR=${EXAMPLESDIR}

PERL_CONFIGURE=	yes

MAN3=		Apache::MVC.3 \
		CGI::Maypole.3 \
		Maypole.3 \
		Maypole::CLI.3 \
		Maypole::Model::Base.3 \
		Maypole::Model::CDBI.3 \
		Maypole::View::Mason.3 \
		Maypole::View::TT.3 \
		Maypole::Workflow.3

DOCS=		About.pod \
		Beer.pod \
		BuySpy.pod \
		Flox.pod \
		Model.pod \
		Overview.pod \
		Request.pod \
		StandardTemplates.pod \
		Templates.pod \
		View.pod \
		makedoc.pl
EXAMPLES=	BeerDB.pm
TMPL_BEER=	addnew
TMPL_CUSTOM=	frontpage \
		header
TMPL_FACTORY=	addnew \
		edit \
		header \
		list \
		macros \
		navbar \
		pager \
		search_form \
		view

pre-patch:
	@ ${SED} ${PKGMSG_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${PKGDIR}/pkg-message > ${PKGMESSAGE}

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
	@ ${MKDIR} ${EXAMPLESDIR}
.for FILE in ${EXAMPLES}
	@ ${INSTALL_DATA} ${WRKSRC}/ex/${FILE} ${EXAMPLESDIR}
.endfor
.endif
	@ ${MKDIR} ${DATADIR}/templates/beer
	@ ${MKDIR} ${DATADIR}/templates/custom
	@ ${MKDIR} ${DATADIR}/templates/factory
.for FILE in ${TMPL_BEER}
	@ ${INSTALL_DATA} ${WRKSRC}/templates/beer/${FILE} ${DATADIR}/templates/beer/
.endfor
.for FILE in ${TMPL_CUSTOM}
	@ ${INSTALL_DATA} ${WRKSRC}/templates/custom/${FILE} ${DATADIR}/templates/custom/
.endfor
.for FILE in ${TMPL_FACTORY}
	@ ${INSTALL_DATA} ${WRKSRC}/templates/factory/${FILE} ${DATADIR}/templates/factory/
.endfor
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=		"Perl 5.6 or newer required. Install lang/perl5 or lang/perl5.8 and try again."
.endif

.include <bsd.port.post.mk>
