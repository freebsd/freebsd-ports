# Created by: Mita Yoshio <mita@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ghostscript
PORTVERSION=	7.07
PORTREVISION=	13
CATEGORIES=	print japanese
PKGNAMESUFFIX=	7-jpnfont

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese font support for Ghostscript 7.x

RUN_DEPENDS=	${LOCALBASE}/share/fonts/std.ja_JP/Ryumin-Light.gs7:japanese/font-std \
		${LOCALBASE}/share/ghostscript/Resource/CIDFont/Ryumin-Light:print/ghostscript7-commfont

USES=		metaport ghostscript:7,run

.include <bsd.port.mk>
