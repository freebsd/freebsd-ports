# New ports collection makefile for:    husky-hpt
# Date created:                         6 January 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	hpt
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	news mail
DISTNAME=	${PORTNAME}_${PORTVERSION}-${PORTREVISION}

MAINTAINER=	fjoe@FreeBSD.org

LIB_DEPENDS=	fidoconfig.0:${PORTSDIR}/news/husky-fidoconf

USE_REINPLACE=	yes

MAN1=		hpt.1 hptlink.1 hpttree.1 txt2pkt.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's^/path/to/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/hptlink.1
	@${REINPLACE_CMD} -e 's^/some/path/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/hpttree.1
	@${REINPLACE_CMD} -e 's^/fido/etc/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/txt2pkt.1

post-build:
	@cd ${WRKSRC}/doc && ${GMAKE}

post-install:
	@cd ${WRKSRC}/doc && ${GMAKE} install

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base/Makefile.inc"
.include <bsd.port.post.mk>
