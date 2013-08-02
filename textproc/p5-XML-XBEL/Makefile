# Created by: Aaron Straup Cope <ascope@cpan.org>
# $FreeBSD$

PORTNAME=	XML-XBEL
PORTVERSION=	1.4
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OOP for reading and writing XBEL documents

BUILD_DEPENDS=	p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	XML::XBEL.3 \
	XML::XBEL::Alias.3 \
	XML::XBEL::Bookmark.3 \
	XML::XBEL::Folder.3 \
	XML::XBEL::Separator.3 \
	XML::XBEL::base.3 \
	XML::XBEL::container.3 \
	XML::XBEL::item.3 \
	XML::XBEL::node.3 \
	XML::XBEL::serialize.3 \
	XML::XBEL::thingy.3 \
	XML::XBEL::url.3

.include <bsd.port.mk>
