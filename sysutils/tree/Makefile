# New ports collection makefile for:	tree
# Date created:		2001/12/24
# Whom:			Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tree
PORTVERSION=	1.5.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://mama.indstate.edu/linux/tree/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display a tree-view of directories with optional color or HTML output

MAKE_ENV+=	MKDIR="${MKDIR}"

MAN1=		tree.1
PLIST_FILES=	bin/tree

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s:iswprint:isprint:" ${WRKSRC}/tree.c
.endif

.include <bsd.port.post.mk>
