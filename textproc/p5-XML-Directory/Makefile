# New ports collection makefile for:	XML::Directory
# Date created:		4 Sep 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-Directory
PORTVERSION=	0.84
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/RDF/Notation3.pm:${PORTSDIR}/textproc/p5-RDF-Notation3
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Directory.3 XML::Directory::Apache.3 \
		XML::Directory::Exception.3 XML::Directory::SAX.3 \
		XML::Directory::String.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-patch:
		@find ${WRKSRC} -name "*.pm" | xargs ${PERL} -pi -e \
		'$$package=$$1 if /^package\s+([^\s;]*);/; s!^require 5.005_62;!!; s!^use warnings;!!; s!^our\s+(\$$|@)(VERSION|ISA|EXPORT|EXPORT_OK)\s+=!$$1$${package}::$$2=!;'

.include <bsd.port.mk>
