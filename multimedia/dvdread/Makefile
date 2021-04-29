PORTNAME=	dvdread
DISTVERSION=	g20160701
PORTREVISION=	2
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/silum/dvdread/commit/
PATCHFILES=	3bd3e448668b95da784159bf5733b5169831b026.patch:-p1 \
		584758674f6e9230a3c30046097db269fb0905e1.patch:-p1

MAINTAINER=	daniel.engberg.lists@pyret.net
COMMENT=	Utility to create ISO images of encrypted DVDs

LICENSE=	GPLv3

LIB_DEPENDS=	libdvdcss.so:multimedia/libdvdcss \
		libdvdread.so:multimedia/libdvdread

USES=		localbase:ldflags
USE_CSTD=	c99

USE_GITHUB=	yes
GH_ACCOUNT=	xrgtn
GH_TAGNAME=	81d07990

# Empty
ALL_TARGET=

PLIST_FILES=	bin/dvdread

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS REGION

REGION_DESC=	Disable automatic removal of region lock in IFO files
REGION_EXTRA_PATCHES=	${FILESDIR}/extrapatch-region

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvdread ${STAGEDIR}${PREFIX}/bin
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dvdread

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
