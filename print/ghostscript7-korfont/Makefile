# Created by: Mita Yoshio <mita@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ghostscript
PORTVERSION=	7.07
PORTREVISION=	8
CATEGORIES=	print korean
MASTER_SITES=	# empty
PKGNAMESUFFIX=	7-korfont
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Korean font support for Ghostscript 7.x

RUN_DEPENDS=	${LOCALBASE}/share/fonts/CIDFont/Munhwa-Regular:${PORTSDIR}/korean/munhwafonts-cid \
		${LOCALBASE}/share/ghostscript/Resource/CIDFont/HYSMyeongJo-Medium:${PORTSDIR}/print/ghostscript7-commfont

# set these forcibly
USES=		ghostscript:7,run
NO_BUILD=		yes
DEPENDS_ARGS+=		-DA4

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
