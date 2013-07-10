# Created by: Oliver Braun <obraun@informatik.unibw-muenchen.de>
# $FreeBSD$

PORTNAME=	frantk
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	x11-toolkits haskell
MASTER_SITES=	http://www.dcs.gla.ac.uk/~meurig/FranTk/
PKGNAMEPREFIX=	hs-
DISTNAME=	FranTk${PORTVERSION:S/./_/}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A GUI library for Haskell on top of Tcl-Tk

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

USES=		gmake

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.elif ${ARCH} == "ia64"
BROKEN=		Does not compile
.endif

WRKSRC=		${WRKDIR}/FranTk1.1/src

ALL_TARGET=	hugs
INSTALL_TARGET=	install_hugs
PLIST_SUB+=	HUGS=""
PLIST_SUB+=	GHC="@comment "

post-patch:
	@${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/frantk.conf

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} ${WRKDIR}/FranTk1.1/doc/frantk.pdf ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
