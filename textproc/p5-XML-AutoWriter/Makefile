# New ports collection makefile for:	XML::AutoWriter
# Date created:		9 Jan 2004
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-AutoWriter
PORTVERSION=	0.38
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS=	${SITE_PERL}/fields.pm:${PORTSDIR}/devel/p5-base
.endif

.include <bsd.port.post.mk>
