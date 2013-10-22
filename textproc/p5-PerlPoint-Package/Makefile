# Created by: mat
# $FreeBSD$

PORTNAME=	PerlPoint-Package
PORTVERSION=	0.45.2
DISTVERSION=	${PORTVERSION:C/\.(.)$/\1/}
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PerlPoint is both a presentation and a documentation toolset

BUILD_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_STAGE=	yes

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
	cd ${WRKSRC}/doc; ${FIND} . | ${CPIO} -padm ${DOCSDIR}
	cd ${WRKSRC}; ${FIND} utilities | ${CPIO} -padm ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/demo; ${FIND} . | ${CPIO} -padm ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
