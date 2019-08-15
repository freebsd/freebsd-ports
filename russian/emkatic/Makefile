# Created by: Andrey Fesenko <andrey@bsdnir.info>
# $FreeBSD$

PORTNAME=	emkatic
PORTVERSION=	0.36
PORTREVISION=	4
CATEGORIES=	russian emulators
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}
MASTER_SITES=	SF/${PORTNAME}/eMKatic%20Source
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	andrey@bsdnir.info
COMMENT=	Emulator of Elektronika RPN programmable calculator series

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		fpc lazarus:flavors
USE_FPC=	cairo chm fcl-base fcl-image fcl-json fcl-registry fcl-xml \
		pasjpeg regexpr rtl-extra x11
USE_XORG=	x11

LAZARUS_PROJECT_FILES=	emkatic.lpi
LAZBUILD_ARGS=		-d --pcp=${WRKSRC}/tmppcp

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*
PORTDOCS=	CHANGELOG.*.txt README.*.txt

gtk2_CONFLICTS_INSTALL=	ru-${PORTNAME}-qt5
qt5_CONFLICTS_INSTALL=	ru-${PORTNAME}-gtk2

OPTIONS_DEFINE=		DOCS PORTAUDIO
OPTIONS_DEFAULT=	PORTAUDIO

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio

.if ${FLAVOR:Ugtk2:Mgtk2}
USE_GNOME+=	cairo
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
