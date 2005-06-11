# New ports collection makefile for:	p5-PerlPoint-Package
# Date created:		8 Jun 2004
# Whom:	      		mat
#
# $FreeBSD$
#

PORTNAME=	PerlPoint-Package
PORTVERSION=	0.39
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PerlPoint
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	mat@FreeBSD.org
COMMENT=	PerlPoint is both a presentation and a documentation toolset

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN1=		pp2sdf.1
MAN3=		PerlPoint::Anchors.3 \
		PerlPoint::Backend.3 \
		PerlPoint::Constants.3 \
		PerlPoint::Parser.3 \
		PerlPoint::Tags.3 \
		PerlPoint::Tags::Basic.3 \
		PerlPoint::Tags::CPPP.3 \
		PerlPoint::Tags::SDF.3

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
