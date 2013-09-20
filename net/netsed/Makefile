# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	netsed
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	# no original distfile site available
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alters the contents of network packets in real time

MAKE_ARGS=	CFLAGS="${CFLAGS}"

WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
