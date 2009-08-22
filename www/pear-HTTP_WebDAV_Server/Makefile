# Ports collection makefile for:  HTTP_WebDAV_Server
# Date created:			  14 Nov 2008
# Whom:				  Wen Heping<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	HTTP_WebDAV_Server
PORTVERSION=	1.0.0.r4
CATEGORIES=	www devel pear
DISTNAME=	${PORTNAME}-1.0.0RC4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	WebDAV Server Baseclass

CATEGORY=	HTTP/WebDAV
FILES=		Server.php Server/Filesystem.php \
		Tools/_parse_lockinfo.php \
		Tools/_parse_propfind.php \
		Tools/_parse_proppatch.php \
		db/Fileserver.sql
DOCS=		README dav.txt
_DOCSDIR=	.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
