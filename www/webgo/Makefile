# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webgo
PORTVERSION=	0.1.0.${SVNVERSION}
CATEGORIES=	www
MASTER_SITES=	LOCAL/jlaffaye
DISTNAME=	${PORTNAME}-${SVNVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Simplest way to write web applications in the Go programming language

SVNVERSION=	20120419

GO_PKGNAME=	${SUBLIBDIR}/web

SUBLIBDIR=	github.com/hoisie

NO_STAGE=	yes
do-install:
	${MKDIR} ${GO_LOCAL_LIBDIR}/${SUBLIBDIR}
	${INSTALL_DATA} ${GO_WRKDIR_PKG}/${SUBLIBDIR}/web.a ${GO_LOCAL_LIBDIR}/${SUBLIBDIR}
	${MKDIR} ${GO_LOCAL_SRCDIR}/${GO_PKGNAME}
	(cd ${GO_WRKSRC}/ && ${COPYTREE_SHARE} \* ${GO_LOCAL_SRCDIR}/${GO_PKGNAME})

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
