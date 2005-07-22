# New ports collection makefile for:	p5-Maypole
# Date created:				Apr 2 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Maypole
PORTVERSION=	2.10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/T/TE/TEEJAY
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
		${SITE_PERL}/Template/Plugin/Class.pm:${PORTSDIR}/www/p5-Template-Plugin-Class \
		${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/Lingua/EN/Inflect/Number.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Number \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/CGI/Simple.pm:${PORTSDIR}/www/p5-CGI-Simple \
		${SITE_PERL}/HTTP/Headers.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	MODPERL "mod_perl support" on

.include <bsd.port.pre.mk>

.if defined(WITH_MODPERL)
.if defined(WITH_APACHE2)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache2/Request.pm:${PORTSDIR}/www/p5-libapreq2
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache2/Request.pm:${PORTSDIR}/www/p5-libapreq2
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq
.endif
.endif

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGMSG_SUB=	DOCSDIR=${DOCSDIR} \
		DATADIR=${DATADIR} \
		EXAMPLESDIR=${EXAMPLESDIR}

PERL_CONFIGURE=	yes

MAN3=		Apache::MVC.3 \
		CGI::Maypole.3 \
		Maypole.3 \
		Maypole::Application.3 \
		Maypole::CLI.3 \
		Maypole::Config.3 \
		Maypole::Constants.3 \
		Maypole::Headers.3 \
		Maypole::Manual.3 \
		Maypole::Manual::About.3 \
		Maypole::Manual::Beer.3 \
		Maypole::Manual::BuySpy.3 \
		Maypole::Manual::Flox.3 \
		Maypole::Manual::Model.3 \
		Maypole::Manual::Plugins.3 \
		Maypole::Manual::Request.3 \
		Maypole::Manual::StandardTemplates.3 \
		Maypole::Manual::View.3 \
		Maypole::Manual::Workflow.3 \
		Maypole::Model::Base.3 \
		Maypole::Model::CDBI.3 \
		Maypole::Model::CDBI::Plain.3 \
		Maypole::Session.3 \
		Maypole::View::Base.3 \
		Maypole::View::TT.3

DOC_FILES=	../Manual.pod \
		About.pod \
		Beer.pod \
		BuySpy.pod \
		Flox.pod \
		Model.pod \
		Request.pod \
		StandardTemplates.pod \
		View.pod \
		Workflow.pod
EXAMPLE_FILES=	BeerDB.pm
TEMPLATE_FILES=	maypole.css \
		beer/addnew \
		factory/addnew \
		factory/edit \
		factory/footer \
		factory/frontpage \
		factory/header \
		factory/list \
		factory/macros \
		factory/maypole \
		factory/navbar \
		factory/pager \
		factory/search_form \
		factory/title \
		factory/view

pre-patch:
	@ ${SED} ${PKGMSG_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${PKGDIR}/pkg-message > ${PKGMESSAGE}

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for FILE in ${DOC_FILES}
	@ ${INSTALL_DATA} ${WRKSRC}/lib/Maypole/Manual/${FILE} ${DOCSDIR}
.endfor
	@ ${MKDIR} ${EXAMPLESDIR}
.for FILE in ${EXAMPLE_FILES}
	@ ${INSTALL_DATA} ${WRKSRC}/ex/${FILE} ${EXAMPLESDIR}
.endfor
.endif
	@ ${MKDIR} ${DATADIR}/templates/beer
	@ ${MKDIR} ${DATADIR}/templates/factory
.for FILE in ${TEMPLATE_FILES}
	@ ${INSTALL_DATA} ${WRKSRC}/templates/${FILE} ${DATADIR}/templates/${FILE}
.endfor
	@ ${CAT} ${PKGMESSAGE}

.if ${PERL_LEVEL} < 500600
IGNORE=		Perl 5.6 or newer required. Install lang/perl5 or lang/perl5.8 and try again.
.endif

.include <bsd.port.post.mk>
