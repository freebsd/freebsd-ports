# New ports collection makefile for:    algae
# Date created:         18 May 2003
# Whom:                 Michael Neumann <mneumann@ntecs.de>
#
# $FreeBSD$
#

PORTNAME=	algae
PORTVERSION=	4.3.6
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	A programming language for numerical analysis

GNU_CONFIGURE=	yes

ALGAE_VERSION=	${PORTVERSION}
PLIST_SUB=	ALGAE_VERSION=${ALGAE_VERSION}

MAN1=	algae.1
INFO=	algae

post-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,g' \
		${WRKSRC}/src/mem.h \
		${WRKSRC}/superlu/sp_coletree.c \
		${WRKSRC}/superlu/util.h

.include <bsd.port.pre.mk>

.if ( ${ARCH} == "alpha" && ${OSVERSION} > 502102 ) || ${ARCH} == "sparc64"
BROKEN=		"Configure fails on alpha 5.x and sparc64"
.endif

.include <bsd.port.post.mk>
