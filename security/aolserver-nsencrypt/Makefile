# New ports collection makefile for:	aolserver-nsencrypt
# Date created:		12 Oct 2006
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aolserver-nsencrypt
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	security www
MASTER_SITES=	SF/aolserver/nsencrypt/${PORTVERSION}
DISTFILES=	nsencrypt-${PORTVERSION}-src.tar.gz
DIST_SUBDIR=	aolserver

MAINTAINER=	mm@FreeBSD.org
COMMENT=	OpenSSL data encryption module for AOLserver

WRKSRC=		${WRKDIR}/nsencrypt-${PORTVERSION}

AOLSERVERBASE?=	aolserver
BUILD_DEPENDS+=	${LOCALBASE}/${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS+=	${LOCALBASE}/${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
PLIST_SUB+=	AOLSERVERBASE=${AOLSERVERBASE}

USE_OPENSSL=	yes
USE_GMAKE=	yes

MAKE_ARGS=	AOLSERVER="${LOCALBASE}/${AOLSERVERBASE}" \
		OPENSSL="${OPENSSLBASE}"

PLIST_FILES=	${AOLSERVERBASE}/bin/nsencrypt.so \
		${AOLSERVERBASE}/lib/libnsencrypt.a \
		${AOLSERVERBASE}/lib/libnsencrypt.so

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog readme.txt
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e '/^MODOBJS  =.*/{p;s/MODOBJS  =/OBJS  +=/g;}' \
		-e '/^MODLIBS  =.*/{p;s/MODLIBS  =/DLLLIBS  +=/g;}' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
