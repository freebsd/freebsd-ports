# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nsmcrypt
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	security www
MASTER_SITES=	http://www.aolserver.cz/download/
PKGNAMEPREFIX=	aolserver-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	aolserver

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AOLserver interface to mcrypt library

PORTSCOUT=	skipv:2.0

WRKSRC=		${WRKDIR}

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

AOLSERVERBASE?=	aolserver
LIB_DEPENDS+=	mcrypt.8:${PORTSDIR}/security/mcrypt
BUILD_DEPENDS+=	${LOCALBASE}/${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS+=	${LOCALBASE}/${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver

USE_GMAKE=	yes
MAKEFILE=	Makefile.ns

USE_TCL=	84+

PLIST_FILES=	${AOLSERVERBASE}/bin/nsmcrypt.so \
		${AOLSERVERBASE}/lib/libnsmcrypt.a \
		${AOLSERVERBASE}/lib/libnsmcrypt.so

NO_STAGE=	yes
.include <bsd.port.pre.mk>

CFLAGS+=	"-I${LOCALBASE}/include"
MAKE_ARGS+=	NSHOME="${LOCALBASE}/${AOLSERVERBASE}" \
		DLLLIBS="-L${LOCALBASE}/lib -lmcrypt" \
		MODLIBS="-L${LOCALBASE}/lib -lmcrypt"

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS CHANGES COPYING README
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/^CFLAGS   =/CFLAGS  +=/g' \
	-e 's/^MODLIBS  =/MODLIBS +=/g' \
	-e '/^OBJS     =.*/{n;s/.*/MODOBJS  = $$(OBJS)/g;G;}' \
		${WRKSRC}/${MAKEFILE}

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
