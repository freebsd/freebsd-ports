# New ports collection makefile for:	webgo
# Date created:				Nov 22, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	webgo
PORTVERSION=	0.1.0.${SVNVERSION}
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	LOCAL/jlaffaye
DISTNAME=	${PORTNAME}-${SVNVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Simplest way to write web applications in the Go programming language

SVNVERSION=	20110915
PLIST_FILES=	${GO_LIBDIR}/web.a

USE_GO=		yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
