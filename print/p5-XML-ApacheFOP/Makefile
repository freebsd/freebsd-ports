# New ports collection makefile for:   p5-XML-ApacheFOP
# Date created:                        27 Feb 2006
# Whom:                                Simun Mikecin <numisemis@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	XML-ApacheFOP
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Access Apache FOP from Perl to create PDF files using XSL-FO

BUILD_DEPENDS=	${SITE_PERL}/Java.pm:${PORTSDIR}/devel/p5-Java \
		${LOCALBASE}/share/fop/build/fop.jar:${PORTSDIR}/textproc/fop
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::ApacheFOP.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>

