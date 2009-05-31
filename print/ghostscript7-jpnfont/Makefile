# New ports collection makefile for:	ghostscript
# Date created:		14 Jan 2002
# Whom:			Mita Yoshio <mita@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ghostscript7-jpnfont
PORTVERSION=	7.07
PORTREVISION=	7
CATEGORIES=	print japanese
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Japanese font support for Ghostscript 7.x

RUN_DEPENDS=	${LOCALBASE}/share/fonts/std.ja_JP/Ryumin-Light:${PORTSDIR}/japanese/font-std \
		${LOCALBASE}/share/ghostscript/Resource/CIDFont/Ryumin-Light:${PORTSDIR}/print/ghostscript7-commfont

# set these forcibly
USE_GHOSTSCRIPT_RUN=	7
NO_BUILD=		yes
DEPENDS_ARGS+=		-DA4

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
