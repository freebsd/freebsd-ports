# ex:ts=8
# Ports collection makefile for:	Flickr::Upload
# Date created:			Apr 27, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Flickr-Upload
PORTVERSION=	1.18
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Flickr
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Upload images to flickr.com

BUILD_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/Parser/Lite/Tree.pm:${PORTSDIR}/textproc/p5-XML-Parser-Lite-Tree
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	thickr_upload.1 flickr_upload.1
MAN3=	Flickr::Upload.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>

