# New ports collection makefile for:	ru-muttprint
# Date Created:         04 April 2003
# Whom:                 Alex Semenyaka <alexs@snark.ratmir.ru>
#
# $FreeBSD$
#

PORTNAME=	muttprint
CATEGORIES=	russian print

MAINTAINER=	alexs@snark.rinet.ru
COMMENT=	Print in Russian

MASTERDIR=	${.CURDIR}/../../print/muttprint
ADD_TRANS=	${.CURDIR}/files/translation-??.pl
USE_REINPLACE=	yes

pre-build:
	@${REINPLACE_CMD} '/^\\\\usepackage\[T1\]{fontenc}/d' ${WRKSRC}/${PORTNAME}
	@${CP} ${ADD_TRANS} ${WRKSRC}/translations/

.include "${MASTERDIR}/Makefile"
