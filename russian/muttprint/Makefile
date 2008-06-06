# New ports collection makefile for:	ru-muttprint
# Date Created:         04 April 2003
# Whom:                 Alex Semenyaka <alexs@snark.ratmir.ru>
#
# $FreeBSD$
#

PORTNAME=	muttprint
PORTREVISION=	4
CATEGORIES=	russian print

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print in Russian

MASTERDIR=	${.CURDIR}/../../print/muttprint
ADD_TRANS=	${.CURDIR}/files/translation-??.pl

pre-build:
	@${REINPLACE_CMD} '/^\\\\usepackage\[T1\]{fontenc}/d' ${WRKSRC}/${PORTNAME}
	@${CP} ${ADD_TRANS} ${WRKSRC}/translations/

.include "${MASTERDIR}/Makefile"
