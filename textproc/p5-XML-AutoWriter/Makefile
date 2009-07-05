# New ports collection makefile for:	XML::AutoWriter
# Date created:		9 Jan 2004
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-AutoWriter
PORTVERSION=	0.40
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
DISTNAME=	${PORTNAME}-0.4
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl module for DOCTYPE based XML output

PERL_CONFIGURE=	yes

MAN3=		XML::AutoWriter.3 \
		XML::Doctype::AttDef.3 \
		XML::ValidWriter.3 \
		XML::Doctype::ElementDecl.3 \
		XML::Doctype.3

post-patch:
	${RM} ${WRKSRC}/lib/XML/*.orig

.include <bsd.port.mk>
