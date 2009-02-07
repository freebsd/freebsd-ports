# New ports collection makefile for:	tree
# Date created:		2001/12/24
# Whom:			Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tree
PORTVERSION=	1.5.2.2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://mama.indstate.edu/linux/tree/ \
		CENKES
EXTRACT_SUFX=	.tgz

MAINTAINER=	gb@isis.u-strasbg.fr
COMMENT=	Display a tree-view of directories with optional color or HTML output

MAKE_ENV+=	MKDIR="${MKDIR}"

MAN1=		tree.1
PLIST_FILES=	bin/tree

PORTDOCS=	CHANGES LICENSE README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
