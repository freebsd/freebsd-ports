# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	go-text
PORTVERSION=	20130502
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/gblach/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Go package for manipulating paragraphs of text

SUBLIBDIR=	github.com/kr
GO_PKGNAME=	${SUBLIBDIR}/text

do-install:
	${MKDIR} ${GO_LOCAL_LIBDIR}/${SUBLIBDIR}
	${INSTALL_DATA} ${GO_WRKDIR_PKG}/${SUBLIBDIR}/text.a ${GO_LOCAL_LIBDIR}/${SUBLIBDIR}
	${MKDIR} ${GO_LOCAL_SRCDIR}/${GO_PKGNAME}
	${INSTALL_DATA} ${GO_WRKSRC}/indent.go ${GO_LOCAL_SRCDIR}/${GO_PKGNAME}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
