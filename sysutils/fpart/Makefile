# New ports collection makefile for:	fpart
# Date created:		24 Nov 2011
# Whom:			Ganael Laplanche <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	fpart
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://contribs.martymac.org/fpart/
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Sort files and divide them into partitions

LICENSE=	BSD

MANCOMPRESSED=	yes
MAN1=		fpart.1
PLIST_FILES=	bin/fpart
PORTDOCS=	Changelog README TODO

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800067
BROKEN=	needs getline() and strnlen()
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
