# New ports collection makefile for:	XML::XQL
# Date created:				Sat Nov 23 17:24:19 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-XQL
PORTVERSION=	0.67
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	lioux@FreeBSD.org

RUN_DEPENDS=	${PBASE}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${PBASE}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${PBASE}/Parse/Yapp.pm:${PORTSDIR}/devel/p5-Parse-Yapp \
		${PBASE}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		XML::XQL.3 XML::XQL::DOM.3 XML::XQL::Date.3 \
		XML::XQL::Query.3 XML::XQL::Tutorial.3

PBASE=		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

.include <bsd.port.mk>
