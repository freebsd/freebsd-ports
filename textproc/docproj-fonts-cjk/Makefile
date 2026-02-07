PORTNAME=	docproj-fonts-cjk
PORTVERSION=	20221225
CATEGORIES=	textproc chinese
MASTER_SITES=	https://github.com/googlefonts/noto-cjk/raw/Sans2.004/ \
		https://github.com/googlefonts/noto-cjk/raw/Sans2.004/Sans/SubsetOTF/JP/:jp \
		https://github.com/googlefonts/noto-cjk/raw/Sans2.004/Sans/SubsetOTF/KR/:kr \
		https://github.com/googlefonts/noto-cjk/raw/Sans2.004/Sans/SubsetOTF/SC/:sc \
		https://github.com/googlefonts/noto-cjk/raw/Sans2.004/Sans/SubsetOTF/TC/:tc
DISTFILES=	LICENSE \
		NotoSansJP-Medium.otf:jp \
		NotoSansKR-Medium.otf:kr \
		NotoSansSC-Medium.otf:sc \
		NotoSansTC-Medium.otf:tc
DIST_SUBDIR=	Noto/CJK/2.004
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CJK fonts required by the FreeBSD Documentation Project
WWW=		https://www.freebsd.org/docproj

LICENSE=	OFL11
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/LICENSE

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${DOCPROJ_FONTS:S|^|${DATADIR}/|}

DOCPROJ_FONTS=	NotoSansJP-Medium.otf \
		NotoSansKR-Medium.otf \
		NotoSansSC-Medium.otf \
		NotoSansTC-Medium.otf

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${DOCPROJ_FONTS} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
