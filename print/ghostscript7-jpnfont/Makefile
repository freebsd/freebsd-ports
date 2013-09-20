# Created by: Mita Yoshio <mita@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ghostscript
PORTVERSION=	7.07
PORTREVISION=	11
CATEGORIES=	print japanese
MASTER_SITES=	# empty
PKGNAMESUFFIX=	7-jpnfont
DISTFILES=	# empty

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Japanese font support for Ghostscript 7.x

RUN_DEPENDS=	${LOCALBASE}/share/fonts/std.ja_JP/Ryumin-Light.gs7:${PORTSDIR}/japanese/font-std \
		${LOCALBASE}/share/ghostscript/Resource/CIDFont/Ryumin-Light:${PORTSDIR}/print/ghostscript7-commfont

# set these forcibly
USE_GHOSTSCRIPT_RUN=	7
NO_BUILD=		yes
DEPENDS_ARGS+=		-DA4

NO_STAGE=	yes
do-install:
	@${DO_NADA}

.include <bsd.port.mk>
