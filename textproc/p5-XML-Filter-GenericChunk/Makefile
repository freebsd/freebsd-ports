# New ports collection makefile for:	XML::Filter::GenericChunk
# Date created:				2.7.2003
# Whom:					Hansjoerg Pehofer <hansjoerg.pehofer@uibk.ac.at>
#
# $FreeBSD$
#

PORTNAME=	XML-Filter-GenericChunk
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
#MASTER_SITE_SUBDIR=	XML
MASTER_SITE_SUBDIR=	../by-authors/id/P/PH/PHISH
PKGNAMEPREFIX=	p5-

MAINTAINER=	hansjoerg.pehofer@uibk.ac.at
COMMENT=	"Base Class for SAX Filters parsing WellBallanced Chunks."

BUILD_DEPENDS=	${PERL_ABASE}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/XML/SAX/Base.pm:${PORTSDIR}/textproc/p5-XML-SAX-Base
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
PERL_ABASE=     ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}

MAN3=		XML::Filter::CharacterChunk.3 \
		XML::Filter::GenericChunk.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
