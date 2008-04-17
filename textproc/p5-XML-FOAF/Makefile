# New ports collection makefile for:	textproc/p5-XML-FOAF
# Date created:		2006-09-25
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	XML-FOAF
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/B/BT/BTROTT
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Parse FOAF (Friend of a Friend) data

BUILD_DEPENDS=	${SITE_PERL}/RDF/Core.pm:${PORTSDIR}/textproc/p5-RDF-Core
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::FOAF.3	\
		XML::FOAF::Person.3

post-patch:
	${PERL} -pi -e '$$_ = "" if m|auto_install|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
