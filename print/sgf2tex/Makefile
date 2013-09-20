# Created by: spcoltri@unm.edu
# $FreeBSD$

PORTNAME=	sgf2tex
PORTVERSION=	3.3
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	http://sporadic.stanford.edu/bump/

MAINTAINER=	spcoltri@omcl.org
COMMENT=	Convert a Go game record in SGF format into TeX and provide fonts to make a dvi

USE_TEX=	tex
PLIST_SUB=	MKTEXLSR=${MKTEXLSR}
MAKE_ENV=	TEX_BIN=${TEX_BIN}

MAN1=		sgf2tex.1 sgfsplit.1

TEX_BIN=	${LOCALBASE}/bin/etex
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

NO_STAGE=	yes
.include <bsd.port.mk>
