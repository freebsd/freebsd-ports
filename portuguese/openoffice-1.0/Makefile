# New ports collection makefile for:	OpenOffice.org for Portuguese language
# Date created:		Tue Jun 11 16:47:21 UTC 2002
# Whom:		Martin Blapp <mbr@FreeBSD.org> and Mario Ferreira <lioux@FreeBSD.org>
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
MASTERDIR=	${.CURDIR}/../../editors/openoffice-1.0

NO_LATEST_LINK=	yes
.include "${MASTERDIR}/Makefile"
