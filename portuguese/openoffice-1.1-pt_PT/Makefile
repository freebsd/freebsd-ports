# New ports collection makefile for:	OpenOffice.org for Portuguese language
# Date created:		Sun Nov 9 09:14:11 JST 2003
# Whom:		Martin Blapp <mbr@FreeBSD.org>, Mario Ferreira <lioux@FreeBSD.org> and NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

COMMENT=	Editor texto/gráfico, banco de dados/planilha/navegador integrado
CATEGORIES=	portuguese

.if !defined (LANG) && !defined(USE_LANG)
USE_LANG=	pt_PT.ISO8859-15
.endif
LANG_LIST=	pt_PT.ISO8859-1 pt_PT.ISO_8859-15 pt_PT.ISO_8859-1 \
		pt_BR.ISO8859-1

LANG_PKGNAME=	pt
LANG_EXT=	03
LANG_CONFIGURE_ARG=	PORT
MASTERDIR=	${.CURDIR}/../../editors/openoffice-1.1

.include "${MASTERDIR}/Makefile"
