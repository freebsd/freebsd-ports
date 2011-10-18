# New ports collection makefile for:	textproc/p5-XML-FOAF
# Date created:		2006-09-25
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	XML-FOAF
PORTVERSION=	0.04
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BTROTT
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Parse FOAF (Friend of a Friend) data

RUN_DEPENDS=	p5-Filter>=0:${PORTSDIR}/devel/p5-Filter \
		p5-RDF-Core>=0:${PORTSDIR}/textproc/p5-RDF-Core
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::FOAF.3	\
		XML::FOAF::Person.3

post-patch:
	${PERL} -pi -e '$$_ = "" if m|auto_install|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
