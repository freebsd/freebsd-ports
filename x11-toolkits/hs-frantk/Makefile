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
COMMENT=	GUI library for Haskell on top of Tcl/Tk

USES=		gmake
USE_TK=		84

ALL_TARGET=	hugs
INSTALL_TARGET=	install_hugs

WRKSRC=		${WRKDIR}/FranTk${PORTVERSION}/src

PLIST_SUB+=	HUGS=""
PLIST_SUB+=	GHC="@comment "

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.elif ${ARCH} == "ia64"
BROKEN=		Does not compile
.endif

post-patch:
	@${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/frantk.conf

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/frantk.pdf ${DOCSDIR}
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
