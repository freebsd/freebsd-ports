# New ports collection makefile for:	XML::Directory
# Date created:		4 Sep 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-Directory
PORTVERSION=	0.99
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Returns a content of directory as XML

BUILD_DEPENDS=	${SITE_PERL}/RDF/Notation3.pm:${PORTSDIR}/textproc/p5-RDF-Notation3 \
		${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Directory.3 XML::Directory::Apache.3 \
		XML::Directory::SAX.3 XML::Directory::String.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif

.include <bsd.port.post.mk>
