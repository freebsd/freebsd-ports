# New ports collection makefile for:	XML::Filter::GenericChunk
# Date created:				2.7.2003
# Whom:					Hansjoerg Pehofer <hansjoerg.pehofer@uibk.ac.at>
#
# $FreeBSD$
#

PORTNAME=	XML-Filter-GenericChunk
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/P/PH/PHISH
PKGNAMEPREFIX=	p5-

MAINTAINER=	hansjoerg.pehofer@uibk.ac.at
COMMENT=	"Base Class for SAX Filters parsing WellBallanced Chunks."

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Filter::CharacterChunk.3 \
		XML::Filter::GenericChunk.3


post-patch:
	${PERL} -pi -e '$$_="" if /use warnings/;' \
			${WRKSRC}/t/02filter.t \
			${WRKSRC}/CharacterChunk.pm \
			${WRKSRC}/GenericChunk.pm

.include <bsd.port.mk>
