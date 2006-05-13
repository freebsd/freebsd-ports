# New ports collection makefile for:	Sary
# Date created:		8 October 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	sary
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://sary.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A suffix array library and tools, which provide fast full-text search

USE_GNOME=	glib20 gnomehack gnometarget
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=		sary.1	mksary.1

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|docs||g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${FIND} . ! -name "*Makefile*" | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
