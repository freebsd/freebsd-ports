# Ports collection makefile for:	rubygem-bluecloth
#
# $FreeBSD$

PORTNAME=	bluecloth
PORTVERSION=	1.0.0
CATEGORIES=	www rubygems
MASTER_SITES=	http://www.deveiate.org/code/
DISTNAME=	BlueCloth-${PORTVERSION}

MAINTAINER=	arsptr@internode.on.net
COMMENT=	Ruby implementation of Markdown, a text-to-HTML conversion tool

PLIST_SUB+=	DISTNAME="${DISTNAME}"

BROKEN=		Incorrect pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2007-04-10

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
