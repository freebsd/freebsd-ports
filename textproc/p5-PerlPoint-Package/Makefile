# New ports collection makefile for:	p5-PerlPoint-Package
# Date created:		8 Jun 2004
# Whom:	      		mat
#
# $FreeBSD$
#

PORTNAME=	PerlPoint-Package
PORTVERSION=	0.45.2
DISTVERSION=	${PORTVERSION:C/\.(.)$/\1/}
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PerlPoint is both a presentation and a documentation toolset

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN1=		pp2sdf.1 perlpoint.1
MAN3=		PerlPoint::Anchors.3 \
		PerlPoint::Backend.3 \
		PerlPoint::Constants.3 \
		PerlPoint::Generator.3 \
		PerlPoint::Generator::Object::Page.3 \
		PerlPoint::Generator::SDF.3 \
		PerlPoint::Generator::SDF::Default.3 \
		PerlPoint::Parser.3 \
		PerlPoint::Tags.3 \
		PerlPoint::Tags::Basic.3 \
		PerlPoint::Tags::SDF.3 \
		PerlPoint::Template.3

.if !defined(NOPORTDOCS)
PORTDOCS=	# suck all DOCSDIR

post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc; ${FIND} . | ${CPIO} -padm ${DOCSDIR}
	@cd ${WRKSRC}; ${FIND} utilities | ${CPIO} -padm ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/demo; ${FIND} . | ${CPIO} -padm ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
