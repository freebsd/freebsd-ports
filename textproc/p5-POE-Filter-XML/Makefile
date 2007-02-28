# ex:ts=8
# New ports collection makefile for:	POE::Filter::XML
# Date created:		Aug 19, 2001
# Whom:			Jeff Putsch <jdputsch@comcast.net>
#
# $FreeBSD$
#

PORTNAME=	POE-Filter-XML
PORTVERSION=	0.33
CATEGORIES=	textproc devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A POE Filter for parsing XML

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/XML/SAX/Expat/Incremental.pm:${PORTSDIR}/textproc/p5-XML-SAX-Expat-Incremental \
		${SITE_PERL}/Filter/Template.pm:${PORTSDIR}/devel/p5-Filter-Template
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		POE::Filter::XML.3 \
		POE::Filter::XML::NS.3 \
		POE::Filter::XML::Node.3 \
		POE::Filter::XML::Utils.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801 # required by vendor
IGNORE=	requires at least Perl 5.8.1.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
