# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	goldendict
PORTVERSION=	1.0.1
PORTREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:C|(.*)\.[0-9]*$|\1|}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Feature-rich Qt4 based dictionary lookup program

LICENSE=	GPLv3

LIB_DEPENDS=	hunspell-1.3:${PORTSDIR}/textproc/hunspell \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		vorbis:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USES=		desktop-file-utils pkgconfig
USE_XORG=	xtst
USE_QT4=	corelib gui webkit phonon \
		qmake_build linguist_build moc_build rcc_build script_build uic_build

WRKSRC=		${WRKDIR}

post-patch:
	@${SED} -I.bak -e "s:/usr:${PREFIX}:" ${WRKSRC}/redist/goldendict.desktop

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} INCLUDEPATH+=${LOCALBASE}/include \
		LIBS+=-L${LOCALBASE}/lib ${PORTNAME}.pro

post-install:
	@${MKDIR} ${DATADIR}/locale
	@${INSTALL_DATA} ${WRKSRC}/locale/*.qm ${DATADIR}/locale/

.include <bsd.port.mk>
