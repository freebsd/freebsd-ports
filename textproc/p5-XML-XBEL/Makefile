# New ports collection makefile for: p5-XML-XBEL
# Date created: August 03, 2004
# Whom: Aaron Straup Cope <ascope@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	XML-XBEL
PORTVERSION=	1.2
# PORTREVISION=
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ascope@cpan.org
COMMENT=	OOP for reading and writing XBEL documents

BUILD_DEPENDS=	${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::XBEL.3 \
		XML::XBEL::Alias.3  \
		XML::XBEL::Bookmark.3 \
		XML::XBEL::Folder.3 \
		XML::XBEL::base.3 \
		XML::XBEL::container.3 \
		XML::XBEL::item.3 \
		XML::XBEL::node.3 \
		XML::XBEL::serialize.3 \
		XML::XBEL::thingy.3 \
		XML::XBEL::url.3 \
		XML::XBEL::Separator.3

.include <bsd.port.mk>
