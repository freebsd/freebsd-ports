# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	droid-fonts-ttf
PORTVERSION=	20131024
PORTREVISION=	5
CATEGORIES=	x11-fonts
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Droid typeface family

LICENSE=	APACHE20

USES=		fonts tar:xz

NO_ARCH=	yes
NO_BUILD=	yes

FONTNAME=	Droid

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}/

# maintainer section:
# https://android.googlesource.com/platform/frameworks/base/+/master/data/fonts/

MS_DISTFILES=	fonts.tar.gz
MS_FONTS=	${WRKSRC}/.ms-fonts
MS_MASTER_SITE=	https://android.googlesource.com/platform/frameworks/base/+archive/master/data/
MS_PLIST=	${WRKSRC}/.ms-pkg-plist
MS_VERSION?=	${PORTVERSION}
MS_WRKSRC=	${WRKSRC}/tmp

maketar: do-clean extract
	${MKDIR} ${MS_WRKSRC}/ ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}/
	${FETCH_CMD} -o ${MS_WRKSRC}/${MS_DISTFILES} ${MS_MASTER_SITE}${MS_DISTFILES}
	${TAR} -x -C ${MS_WRKSRC}/ -f ${MS_WRKSRC}/${MS_DISTFILES}
	${LS} ${MS_WRKSRC}/Droid*.ttf | ${SED} 's|${MS_WRKSRC}/||' > ${MS_FONTS}
	${MV} ${MS_WRKSRC}/Droid*.ttf ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}/
	${TAR} -Jc -C ${MS_WRKSRC}/ -f ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}.tar.xz ${PORTNAME}-${MS_VERSION}/
	sudo ${INSTALL} -m 644 ${MS_WRKSRC}/${PORTNAME}-${MS_VERSION}.tar.xz ${DISTDIR}/
	${SED} -i '' -e 's|${PORTVERSION}|${MS_VERSION}|' ${.CURDIR}/Makefile
	cd ${.CURDIR}/ && ${MAKE_CMD} makesum
	${ECHO_MSG} '*** Update from ${PORTVERSION} to ${MS_VERSION} ***'
# genplist
	${SED} 's|^|%%FONTSDIR%%/|' ${MS_FONTS} > ${MS_PLIST}
	${ECHO_CMD} "%%FONTSDIR%%/fonts.dir" >> ${MS_PLIST}
	${ECHO_CMD} "%%FONTSDIR%%/fonts.scale" >> ${MS_PLIST}
	${INSTALL} -m 600 ${MS_PLIST} ${PLIST}

.include <bsd.port.mk>
