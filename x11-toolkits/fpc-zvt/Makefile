# New ports collection makefile for:	fpc-zvt
# Date created:		2006-06-22
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTREVISION=	4
CATEGORIES=	x11-toolkits lang
PKGNAMESUFFIX=	-zvt

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to Zed's Virtual Terminal

USE_FPC=	gtk imlib x11 opengl

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/extra/gnome1/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	ZVT	"Install library components for Zed's Virtual Terminal"	on

.include "${MASTERDIR}/Makefile"
