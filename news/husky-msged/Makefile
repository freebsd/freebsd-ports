# Created by: Max Khon
# $FreeBSD$

PORTNAME=	msged
PORTVERSION=	6.2RC1
PORTREVISION=	2
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

.include "${.CURDIR}/../husky-base/Makefile.inc"
.include <bsd.port.mk>
