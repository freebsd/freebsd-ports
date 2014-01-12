# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ipfmeta
PORTVERSION=	1.3
CATEGORIES=	security
MASTER_SITES=	http://www.sentia.org/downloads/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	ipfmeta - use objects in IPfilter files

USES=		perl5

MAN1=	ipfmeta.1
POD2MAN?=	pod2man

NO_STAGE=	yes
do-build:
	@${POD2MAN} ${WRKSRC}/ipfmeta > ${WRKSRC}/${MAN1}

do-install:
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/ipfmeta ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/ipfmeta
	${INSTALL_DATA} ${WRKSRC}/ipf.* ${PREFIX}/share/ipfmeta

.include <bsd.port.mk>
