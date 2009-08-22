# Ports collection makefile for:  pear-Services_Blogging
# Date created:			  23 June 2008
# Whom:				  Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Services_Blogging
PORTVERSION=	0.2.3
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP interface to Blog

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/XML/RPC.php:${PORTSDIR}/net/pear-XML_RPC
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Services
FILES=		Services/Blogging.php \
		Services/Blogging/Blog.php \
		Services/Blogging/MediaObject.php \
		Services/Blogging/MultipleBlogsInterface.php \
		Services/Blogging/Driver.php \
		Services/Blogging/Post.php \
		Services/Blogging/Exception.php \
		Services/Blogging/XmlRpc.php \
		Services/Blogging/ExtendedDriver.php \
		Services/Blogging/Driver/Blogger.php \
		Services/Blogging/Driver/Exception.php \
		Services/Blogging/Driver/LiveJournal.php \
		Services/Blogging/Driver/MetaWeblog.php

EXAMPLES=	autodiscover.php blogger.cw.php livejournal.cw.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
