# Created by: Stefan Walter <stefan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	museekplus
PORTVERSION=	0.1.13
PORTREVISION=	9
CATEGORIES=	net-p2p
MASTER_SITES=	SF/museek-plus/museek-plus/${PORTVERSION}
DISTNAME=	museek+-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SoulSeek client with separate terminal and Qt based interface

LIB_DEPENDS=	xml\\+\\+:${PORTSDIR}/textproc/libxml++26
BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

USES=		pkgconfig
USE_BZIP2=	yes
USE_SCONS=	yes
USE_FAM=	yes

SCONS_ARGS=	QTDIR=${QT_PREFIX} QT_LIB=qt-mt PREFIX=${PREFIX} VORBIS=yes
DATADIR=	share/museek
MAN1=		musetup.1 mulog.1 museekcontrol.1 muscan.1 muscand.1 museekd.1

OPTIONS_DEFINE=	MUSETUPGTK PYMUCIPHER VORBIS MURMUR MUCOUS OPTIMIZED_CFLAGS DEBUG
OPTIONS_DEFAULT=	MUSETUPGTK PYMUCIPHER VORBIS
MUSETUPGTK_DESC=	Install musetup-gtk
PYMUCIPHER_DESC=	Install python bindings for Mucipher
MURMUR_DESC=		Install PyGTK client
MUCOUS_DESC=		Install Curses Python client

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYMUCIPHER} || ${PORT_OPTIONS:MBINDINGS} || ${PORT_OPTIONS:MMURMUR} || ${PORT_OPTIONS:MCLIENTS} || ${PORT_OPTIONS:MMUCOUS}
USE_PYTHON=	yes
.endif

SCONS_ARGS+=	MUSEEQ=no
PLIST_SUB+=	MUSEEQ="@comment "
SCONS_ARGS+=	QSA=no

.if ${PORT_OPTIONS:MVORBIS}
SCONS_ARGS+=	VORBIS=yes
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
.else
SCONS_ARGS+=	VORBIS=no
.endif

.if ${PORT_OPTIONS:MMUSETUPGTK}
SCONS_ARGS+=	MUSETUPGTK=yes
MAN1+=		musetup-gtk.1
PLIST_SUB+=	MUSETUPGTK=""
.else
SCONS_ARGS+=	MUSETUPGTK=no
PLIST_SUB+=	MUSETUPGTK="@comment "
.endif
.if ${PORT_OPTIONS:MPYMUCIPHER}
SCONS_ARGS+=	PYMUCIPHER=yes
PLIST_SUB+=	PYMUCIPHER=""
.else
SCONS_ARGS+=	PYMUCIPHER=no
PLIST_SUB+=	PYMUCIPHER="@comment "
.endif
.if ${PORT_OPTIONS:MMURMUR}
SCONS_ARGS+=	MURMUR=yes
MAN1+=		murmur.1
PLIST_SUB+=	MURMUR=""
.else
SCONS_ARGS+=	MURMUR=no
PLIST_SUB+=	MURMUR="@comment "
.endif
.if ${PORT_OPTIONS:MMUCOUS}
SCONS_ARGS+=	MUCOUS=yes
MAN1+=		mucous.1
PLIST_SUB+=	MUCOUS=""
.else
SCONS_ARGS+=	MUCOUS=no
PLIST_SUB+=	MUCOUS="@comment "
.endif
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
SCONS_ARGS+=	RELEASE=yes
.else
SCONS_ARGS+=	RELEASE=no
.endif
.if ${PORT_OPTIONS:MDEBUG}
SCONS_ARGS+=	MULOG="cycle,debug"
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "s,%%PYTHONPREFIX_SITELIBDIR%%,${PYTHONPREFIX_SITELIBDIR},g"\
		${WRKSRC}/Mucipher/python/SConscript \
		${WRKSRC}/mucous/pymucous/SConscript \
		${WRKSRC}/murmur/pymurmur/SConscript \
		${WRKSRC}/museekd/SConscript \
		${WRKSRC}/python-bindings/museek/SConscript

post-install:
.if ${PORT_OPTIONS:MMUCOUS}
	@${REINPLACE_CMD} -i "" -e "s,/usr/bin/python,${PYTHON_CMD},g" ${PREFIX}/bin/mucous
.endif
.if ${PORT_OPTIONS:MMUSETUPGTK}
	@${REINPLACE_CMD} -i "" -e "s,/usr/bin/python,${PYTHON_CMD},g" ${PREFIX}/bin/musetup-gtk
.endif
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
