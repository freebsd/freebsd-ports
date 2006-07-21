# ex:ts=8
# Ports collection makefile for:	Flickr::Upload
# Date created:			Apr 27, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Flickr-Upload
PORTVERSION=	1.22
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Flickr
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Upload images to flickr.com

RUN_DEPENDS=	${SITE_PERL}/Flickr/API.pm:${PORTSDIR}/www/p5-Flickr-API \
		${SITE_PERL}/HTTP/Request/Common.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/Parser/Lite/Tree.pm:${PORTSDIR}/textproc/p5-XML-Parser-Lite-Tree
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		flickr_upload.1
MAN3=		Flickr::Upload.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
