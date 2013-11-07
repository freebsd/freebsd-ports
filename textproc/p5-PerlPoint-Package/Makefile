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

.if !defined(NOPORTDOCS)
PORTDOCS=	# suck all DOCSDIR

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc; ${FIND} . | ${CPIO} -padm ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; ${FIND} utilities | ${CPIO} -padm ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/demo; ${FIND} . | ${CPIO} -padm ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
