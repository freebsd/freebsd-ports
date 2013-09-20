# Created by: Tomokatsu SAITO <saito@a2z.co.jp>
# $FreeBSD$

PORTNAME=	ghostscript
PORTVERSION=	7.07
PORTREVISION=	12
CATEGORIES=	print
MASTER_SITES=	# empty
PKGNAMESUFFIX=	7-commfont
DISTFILES=	# empty

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Common files for Ghostscript 7.x CJK font support

BUILD_DEPENDS=	${CMAPDIR}/ac15/cid2code.txt:${PORTSDIR}/print/adobe-cmaps
RUN_DEPENDS=	${CMAPDIR}/ac15/cid2code.txt:${PORTSDIR}/print/adobe-cmaps

NO_WRKSUBDIR=	yes
SUB_FILES=	pkg-message \
		Makefile template.cidfont template.ttcidfont template.font
SUB_LIST=	PORTVERSION="${PORTVERSION}" GS_RESDIR="${GS_RESDIR}"
PLIST_SUB=	GS_RESDIR="${GS_RESDIR}"
PKGMESSAGE=	${WRKDIR}/pkg-message
DEPENDS_ARGS+=	-DA4
# set these forcibly
USE_GHOSTSCRIPT_RUN=7

CONFLICTS=	ghostscript8-[0-9]* \
		ghostscript8-nox11-[0-9]* \
		ghostscript9-[0-9]* \
		ghostscript9-nox11-[0-9]* \
		ghostscript9-agpl-[0-9]* \
		ghostscript9-agpl-nox11-[0-9]*

CMAPDIR?=	${LOCALBASE}/share/fonts/adobe-cmaps
GS_RESDIR?=	share/ghostscript/Resource

post-extract:	apply-slist

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
