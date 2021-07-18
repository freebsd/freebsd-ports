PORTNAME=	texlive
PORTVERSION=	20150523
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tug.org/historic/systems/texlive/2015/
PKGNAMESUFFIX=	-docs
DISTNAME=	${PORTNAME}-${PORTVERSION}-texmf
DIST_SUBDIR=	TeX

MAINTAINER=	freebsd-tex@FreeBSD.org
COMMENT=	TeX Live Typesetting System, documentation

USES=		tar:xz
USE_TEX=	texmf
NO_BUILD=	yes

EXCLUDE_FILES=	\*/doc/man \
	texmf-dist/doc/aleph \
	texmf-dist/doc/lualatex \
	texmf-dist/doc/luatex \
	texmf-dist/doc/xelatex \
	texmf-dist/doc/xetex \
	texmf-dist/doc/otherformats/jadetex \
	texmf-dist/doc/otherformats/xmltex \
	texmf-dist/doc/ptex \
	texmf-dist/doc/platex \
	texmf-dist/doc/uptex \
	texmf-dist/doc/uplatex \
	texmf-dist/doc/fonts/japanese-otf \
	texmf-dist/doc/fonts/japanese-otf-uptex \
	texmf-dist/doc/fonts/jfontmaps \
	texmf-dist/doc/dvips \
	texmf-dist/doc/dvipdfmx

EXTRACT_AFTER_ARGS=| ${TAR} xf - ${EXCLUDE_FILES:S,^,--exclude ${DISTNAME}/,}

do-extract:
	@${MKDIR} ${WRKDIR}

do-install:
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
	    ${EXTRACT_AFTER_ARGS} -C ${STAGEDIR}${PREFIX}/share \
	    --strip-components 1 --no-same-permission --no-same-owner \
	    ${DISTNAME}/texmf-dist/doc

.include <bsd.port.mk>
