# New ports collection makefile for:    husky-msged
# Date created:                         6 January 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	msged
PORTVERSION=	6.2RC1
PORTREVISION=	1
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/${PORTNAME}/6.2%20RC1
DISTNAME=	${PORTNAME}-${PORTVERSION}-stable-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Msged/TE (full-featured FTN mail reader)

LIB_DEPENDS=	fidoconfig.0:${PORTSDIR}/news/husky-fidoconf

MAKE_ARGS=	MSGEDCFG="\\\"~/.msged\\\""

INFO=		msged

post-patch:
	@${REINPLACE_CMD} -e 's,html info,info,' -e 's,install-html install-info,install-info,' ${WRKSRC}/doc/manual/makefile.husky

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/news/husky-base/Makefile.inc"
.include <bsd.port.post.mk>
