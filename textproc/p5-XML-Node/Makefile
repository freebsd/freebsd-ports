# New ports collection makefile for:	p5-XML-Node
# Date created:		13 March 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	XML-Node
PORTVERSION=	0.10
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	wjv@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

PERL_CONFIGURE=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		XML::Node.3

.include <bsd.port.mk>
