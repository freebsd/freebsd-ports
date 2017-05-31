# $FreeBSD$

PORTNAME=	unicode-ucd
PORTVERSION=	9.0.0
CATEGORIES=	misc
MASTER_SITES=	http://www.unicode.org/Public/zipped/${PORTVERSION}/
DISTFILES=	UCD.zip \
		Unihan.zip
DIST_SUBDIR=	unicode/${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Unicode Character Database

# https://fedoraproject.org/wiki/Licensing/MIT#Modern_Style_without_sublicense_.28Unicode.29
LICENSE=	MIT

USES=		zip

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/${PORTNAME}/
# we unpack Unihan.zip but gucharmap wants the Unihan.zip to be present
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Unihan.zip \
		${STAGEDIR}${PREFIX}/share/${PORTNAME}/

.include <bsd.port.mk>
