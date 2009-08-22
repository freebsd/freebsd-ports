# New ports collection makefile for:    husky-fidoconf
# Date created:                         6 January 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	fidoconf
PORTVERSION=	0.14.4
PORTREVISION=	1
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/fidoconfig/0.14-release
DISTNAME=	${PORTNAME}_${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Configuration library for Husky Fidosoft Project

LIB_DEPENDS=	smapi.2:${PORTSDIR}/news/husky-smapi
RUN_DEPENDS=	${LOCALBASE}/etc/fido/huskymak.cfg:${PORTSDIR}/news/husky-base

CONFLICTS=	husky-fidoconf-devel-[0-9]*

USE_LDCONFIG=	yes
INSTALL_TARGET=	install install-man

MAN1=		dumpfcfg.1 fconf2.1 linkedto.1 tparser.1
MLINKS=		fconf2.1 fconf2aquaed.1 \
		fconf2.1 fconf2areasbbs.1 \
		fconf2.1 fconf2fidogate.1 \
		fconf2.1 fconf2golded.1 \
		fconf2.1 fconf2msged.1 \
		fconf2.1 fconf2squish.1
INFO=		fidoconfig

post-patch:
	@${REINPLACE_CMD} -e 's^/fido/etc/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/dumpfcfg.1
	@${REINPLACE_CMD} -e 's^/etc/fido/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/fconf2.1 \
		${WRKSRC}/man/tparser.1

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base/Makefile.inc"
.include <bsd.port.post.mk>
