# New ports collection makefile for:	p5-XML-XSLT
# Date created:				May 26 2001
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	XML-XSLT
PORTVERSION=	0.32
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		xslt-parser.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		XML::XSLT.3

test:
	@cd ${WRKSRC}; ${MAKE} test

.include <bsd.port.mk>
