# New ports collection makefile for:		textproc/goldendict
# Date created:					2009-11-09
# Whom:						bsam
#
# $FreeBSD$
#

PORTNAME=	goldendict
PORTVERSION=	1.0.1
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:C|(.*)\.[0-9]*$|\1|}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	A feature-rich dictionary lookup program (with QT lib)

LIB_DEPENDS=	hunspell-1.3.0:${PORTSDIR}/textproc/hunspell \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		vorbis:${PORTSDIR}/audio/libvorbis

LICENSE=	GPLv3
USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GNOME=	pkgconfig
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

.include <bsd.port.pre.mk>

.if ${OSVERSION}<800067
IGNORE=		wcscasecmp() id not implemented
.endif

.include <bsd.port.post.mk>
