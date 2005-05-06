# New ports collection makefile for:	textproc/p5-PPI
# Date created:				24 March 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PPI
PORTVERSION=	0.906
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/A/AD/ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Analyze and manipulate Perl code without using perl itself

BUILD_DEPENDS=	${SITE_PERL}/Class/Autouse.pm:${PORTSDIR}/devel/p5-Class-Autouse \
		${SITE_PERL}/Test/ClassAPI.pm:${PORTSDIR}/devel/p5-Test-ClassAPI \
		${SITE_PERL}/Class/Inspector.pm:${PORTSDIR}/devel/p5-Class-Inspector \
		${SITE_PERL}/${PERL_ARCH}/List/MoreUtils.pm:${PORTSDIR}/lang/p5-List-MoreUtils \
		${SITE_PERL}/File/Slurp.pm:${PORTSDIR}/devel/p5-File-Slurp \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	PPI.3 \
	PPI::Document.3 \
	PPI::Document::Fragment.3 \
	PPI::Document::Normalized.3 \
	PPI::Dumper.3 \
	PPI::Element.3 \
	PPI::Find.3 \
	PPI::Lexer.3 \
	PPI::Node.3 \
	PPI::Normal.3 \
	PPI::Normal::Standard.3 \
	PPI::Statement.3 \
	PPI::Statement::Compound.3 \
	PPI::Statement::Package.3 \
	PPI::Statement::Scheduled.3 \
	PPI::Statement::Sub.3 \
	PPI::Statement::Variable.3 \
	PPI::Token::HereDoc.3 \
	PPI::Tokenizer.3

post-patch:
	@${RM} ${WRKSRC}/inc/Module/Install/AutoInstall.pm
	@${PERL} -pi -e '$$_="" if m/AutoInstall/' ${WRKSRC}/MANIFEST
	@${PERL} -pi -e '$$_="" if m/Test::More|auto_install/' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires Perl 5.6 or newer. Install lang/perl5 or lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
