# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	goldendict
PORTVERSION=	1.0.1
PORTREVISION=	14
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:C|(.*)\.[0-9]*$|\1|}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Feature-rich Qt4 based dictionary lookup program

LICENSE=	GPLv3

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libhunspell-1.6.so:textproc/hunspell \
		libvorbis.so:audio/libvorbis

NO_WRKSUBDIR=	yes
USES=		compiler:c++11-lang dos2unix iconv:wchar_t pkgconfig qmake qt:4 tar:bzip2
DOS2UNIX_FILES=	processwrapper.cc
USE_XORG=	xtst
USE_QT=		corelib gui webkit phonon \
		linguist_build moc_build rcc_build script_build uic_build
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} 's:/usr:${PREFIX}:' ${WRKSRC}/redist/goldendict.desktop

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/locale
	${INSTALL_DATA} ${WRKSRC}/locale/*.qm ${STAGEDIR}${DATADIR}/locale
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
