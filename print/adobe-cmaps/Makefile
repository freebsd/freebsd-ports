# New ports collection makefile for:    adobe-cmaps
# Date created:         Wed, 10 Apr 2002 02:22:30 +0900
# Whom:                 KATO Tsuguru <tkato@prontomail.com>
#
# $FreeBSD$
#

PORTNAME=	adobe-cmaps
PORTVERSION=	200204
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.gyve.org/pub/gs-cjk/ \
		http://www.matsusaka-u.ac.jp/mirror/gs-cjk/
DIST_SUBDIR=	ghostscript

MAINTAINER=	mita@jp.FreeBSD.org
COMMENT=	Adobe CMap collection

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
RESOURCE=	${PREFIX}/share/ghostscript/Resource

do-install:
	@${MKDIR} ${RESOURCE}/CIDFont
	@${MKDIR} ${RESOURCE}/Font
	@cd ${WRKSRC} && ${FIND} . \! -name '.*' \
		| ${CPIO} --quiet -pdum -R ${SHAREOWN}:${SHAREGRP} ${RESOURCE}

.include <bsd.port.mk>
