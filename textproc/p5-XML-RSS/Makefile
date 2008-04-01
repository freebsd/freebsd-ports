# New ports collection makefile for:	XML::RSS
# Date created:				4th September 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-RSS
PORTVERSION=	1.32
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl extension to manage RDF Site Summary (RSS) files

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser/Expat.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
    		${SITE_PERL}/DateTime/Format/Mail.pm:${PORTSDIR}/devel/p5-DateTime-Format-Mail \
    		${SITE_PERL}/DateTime/Format/W3CDTF.pm:${PORTSDIR}/devel/p5-DateTime-Format-W3CDTF
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::RSS.3

.include <bsd.port.mk>
