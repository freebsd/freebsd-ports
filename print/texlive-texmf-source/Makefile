# $FreeBSD$

PORTNAME=	texlive
PORTVERSION=	20140525
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tug.org/historic/systems/texlive/2014/
PKGNAMESUFFIX=	-texmf-source
DISTNAME=	${PORTNAME}-${PORTVERSION}-texmf
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeX Live Typesetting System, texmf Tree (source)

CONFLICTS_INSTALL=	texlive-base-201[23]*

USES=		tar:xz
USE_TEX=	texmf>=20140525_3
TEXHASHDIRS=	${TEXMFDISTDIR}
NO_BUILD=	yes
NO_WRKSRC=	yes

INCLUDE_FILES=	texmf-dist/source
EXCLUDE_FILES=	texmf-dist/source/fonts/japanese-otf \
		texmf-dist/source/fonts/japanese-otf-uptex \
		texmf-dist/source/fonts/uptex \
		texmf-dist/source/jadetex \
		texmf-dist/source/lambda \
		texmf-dist/source/lualatex \
		texmf-dist/source/luatex \
		texmf-dist/source/platex \
		texmf-dist/source/uplatex \
		texmf-dist/source/xelatex \
		texmf-dist/source/xmltex

EXTRACT_AFTER_ARGS=| ${TAR} xf - ${INCLUDE_FILES:S,^,--include ${DISTNAME}/,} \
    ${EXCLUDE_FILES:S,^,--exclude ${DISTNAME}/,}

do-extract:
	@${MKDIR} ${WRKDIR}

do-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS} -C ${STAGEDIR}${PREFIX}/share \
		--strip-components 1 --no-same-permission --no-same-owner

.include <bsd.port.mk>
