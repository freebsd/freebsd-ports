# New ports collection makefile for:		textproc/goldendict
# Date created:					2009-11-09
# Whom:						bsam
#
# $FreeBSD$
#

PORTNAME=	goldendict
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	BERLIOS
DISTNAME=	${PORTNAME}-${PORTVERSION}-src-x11

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	A feature-rich dictionary lookup program (with QT lib)

LIB_DEPENDS=	hunspell-1.2.0:${PORTSDIR}/hungarian/hunspell \
		vorbis:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GNOME=	pkgconfig
USE_QT_VER=	4
USE_QT4=	linguist
QT_COMPONENTS=	corelib gui webkit \
		qmake_build linguist_build moc_build rcc_build script_build uic_build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

post-patch:
	@${SED} -I.bak -e "s:/usr:${PREFIX}:" ${WRKSRC}/redist/goldendict.desktop

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} INCLUDEPATH+=${LOCALBASE}/include \
		LIBS+=-L${LOCALBASE}/lib ${PORTNAME}.pro

post-install:
	@${MKDIR} ${DATADIR}/locale
	@${INSTALL_DATA} ${WRKSRC}/locale/ru.qm ${DATADIR}/locale/

.include <bsd.port.pre.mk>

.if ${OSVERSION}<800067
IGNORE=		wcscasecmp() id not implemented
.endif

.include <bsd.port.post.mk>
