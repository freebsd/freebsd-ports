# New ports collection makefile for:    husky-fidoconf
# Date created:                         6 January 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	fidoconf
PORTVERSION=	0.14.2
PORTREVISION=	1
CATEGORIES=	news mail
DISTNAME=	${PORTNAME}_${PORTVERSION}-${PORTREVISION}

MAINTAINER=	fjoe@FreeBSD.org

LIB_DEPENDS=	smapi.2:${PORTSDIR}/news/husky-smapi

INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes
INSTALL_TARGET=	install install-man

MAN1=		dumpfcfg.1 fconf2.1 linkedto.1 tparser.1
MLINKS=		fconf2.1 fconf2aquaed.1 \
		fconf2.1 fconf2areasbbs.1 \
		fconf2.1 fconf2fidogate.1 \
		fconf2.1 fconf2golded.1 \
		fconf2.1 fconf2msged.1 \
		fconf2.1 fconf2squish.1

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base/Makefile.inc"
.include <bsd.port.post.mk>
