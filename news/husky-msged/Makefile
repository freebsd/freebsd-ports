# New ports collection makefile for:    husky-base
# Date created:                         6 January 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	msged
PORTVERSION=	6.0.1
CATEGORIES=	news mail
MASTER_SITES=	http://www.physcip.uni-stuttgart.de:8080/fidosoft.husky/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org

LIB_DEPENDS=	fidoconfig.0:${PORTSDIR}/news/husky-fidoconf

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
#MAN1=		hpt.1 hptlink.1 hpttree.1 txt2pkt.1
#MANCOMPRESSED=	yes

#post-build:
#	@cd ${WRKSRC}/doc && ${GMAKE}

#post-install:
#	@cd ${WRKSRC}/doc && ${GMAKE} install

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base/Makefile.inc"
.include <bsd.port.post.mk>
