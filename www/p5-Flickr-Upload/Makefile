# ex:ts=8
# Ports collection makefile for:	Flickr::Upload
# Date created:			Apr 27, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Flickr-Upload
PORTVERSION=	1.32
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Upload images to flickr.com

RUN_DEPENDS=	${SITE_PERL}/Flickr/API.pm:${PORTSDIR}/www/p5-Flickr-API \
		${SITE_PERL}/HTTP/Request/Common.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/Parser/Lite/Tree.pm:${PORTSDIR}/textproc/p5-XML-Parser-Lite-Tree
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		flickr_upload.1
MAN3=		Flickr::Upload.3

.include <bsd.port.mk>
