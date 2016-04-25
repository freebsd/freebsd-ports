# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	goldendict
PORTVERSION=	1.0.1
PORTREVISION=	8
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:C|(.*)\.[0-9]*$|\1|}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Feature-rich Qt4 based dictionary lookup program

LICENSE=	GPLv3

LIB_DEPENDS=	libhunspell-1.3.so:textproc/hunspell \
		libvorbis.so:audio/libvorbis

NO_WRKSUBDIR=	yes
USES=		dos2unix execinfo iconv pkgconfig qmake tar:bzip2
DOS2UNIX_FILES=	processwrapper.cc
USE_XORG=	xtst
USE_QT4=	corelib gui webkit phonon \
		linguist_build moc_build rcc_build script_build uic_build
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} 's:/usr:${PREFIX}:' ${WRKSRC}/redist/goldendict.desktop

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/locale
	${INSTALL_DATA} ${WRKSRC}/locale/*.qm ${STAGEDIR}${DATADIR}/locale
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
