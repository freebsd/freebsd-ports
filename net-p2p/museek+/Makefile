# New ports collection makefile for:	museekplus
# Date created:				06 Aug 2006
# Whom:					Stefan Walter <stefan@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	museekplus
PORTVERSION=	0.1.13
PORTREVISION=	3
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	museek-plus
DISTNAME=	museek+-${PORTVERSION}

MAINTAINER=	silver@ultrasoft.ee
COMMENT=	SoulSeek client with separate terminal and Qt based interface

LIB_DEPENDS=	xml\\+\\+:${PORTSDIR}/textproc/libxml++26
BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

USE_BZIP2=	yes
USE_SCONS=	yes
USE_FAM=	yes

SCONS_ARGS=	QTDIR=${QT_PREFIX} QT_LIB=qt-mt PREFIX=${PREFIX} VORBIS=yes
DATADIR=	share/museek
MAN1=		musetup.1 mulog.1 museekcontrol.1 muscan.1 muscand.1 museekd.1

OPTIONS= \
	MUSEEQ "Install Museeq (Qt3 client)" On \
	QSA "Build Museeq with Qt Script support" On \
	MUSETUPGTK "Install musetup-gtk" On \
	PYMUCIPHER "Install python bindings for Mucipher" On \
	VORBIS "Enable OGG Vorbis support in muscan" On \
	MURMUR "Install PyGTK client" Off \
	MUCOUS "Install Curses Python client" Off \
	OPTIMIZED_CFLAGS "Build with optmizations" Off \
	DEBUG "Build in debug mode" Off

.include <bsd.port.options.mk>

.if defined(WITH_PYMUCIPHER) || defined(WITH_BINDINGS) || defined(WITH_MURMUR) || defined(WITH_CLIENTS) || defined(WITH_MUCOUS)
USE_PYTHON=	yes
.endif

.ifdef(WITH_MUSEEQ)
USE_QT_VER=	3
SCONS_ARGS+=	MUSEEQ=yes
MAN1+=		museeq.1
PLIST_SUB+=	MUSEEQ=""
.ifdef(WITH_QSA)
SCONS_ARGS+=	QSA=yes
LIB_DEPENDS+=	qsa:${PORTSDIR}/devel/qsa
.else
SCONS_ARGS+=	QSA=no
.endif
.else
SCONS_ARGS+=	MUSEEQ=no
PLIST_SUB+=	MUSEEQ="@comment "
SCONS_ARGS+=	QSA=no
.endif
.ifdef(WITH_VORBIS)
SCONS_ARGS+=	VORBIS=yes
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
.else
SCONS_ARGS+=	VORBIS=no
.endif

.include <bsd.port.pre.mk>

.ifdef(WITH_MUSETUPGTK)
SCONS_ARGS+=	MUSETUPGTK=yes
MAN1+=		musetup-gtk.1
PLIST_SUB+=	MUSETUPGTK=""
.else
SCONS_ARGS+=	MUSETUPGTK=no
PLIST_SUB+=	MUSETUPGTK="@comment "
.endif
.ifdef(WITH_PYMUCIPHER)
SCONS_ARGS+=	PYMUCIPHER=yes
PLIST_SUB+=	PYMUCIPHER=""
.else
SCONS_ARGS+=	PYMUCIPHER=no
PLIST_SUB+=	PYMUCIPHER="@comment "
.endif
.ifdef(WITH_MURMUR)
SCONS_ARGS+=	MURMUR=yes
MAN1+=		murmur.1
PLIST_SUB+=	MURMUR=""
.else
SCONS_ARGS+=	MURMUR=no
PLIST_SUB+=	MURMUR="@comment "
.endif
.ifdef(WITH_MUCOUS)
SCONS_ARGS+=	MUCOUS=yes
MAN1+=		mucous.1
PLIST_SUB+=	MUCOUS=""
.else
SCONS_ARGS+=	MUCOUS=no
PLIST_SUB+=	MUCOUS="@comment "
.endif
.ifdef(WITH_OPTIMIZED_CFLAGS)
SCONS_ARGS+=	RELEASE=yes
.else
SCONS_ARGS+=	RELEASE=no
.endif
.ifdef(WITH_DEBUG)
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
.ifdef(WITH_MUCOUS)
	@${REINPLACE_CMD} -i "" -e "s,/usr/bin/python,${PYTHON_CMD},g" ${PREFIX}/bin/mucous
.endif
.ifdef(WITH_MUSETUPGTK)
	@${REINPLACE_CMD} -i "" -e "s,/usr/bin/python,${PYTHON_CMD},g" ${PREFIX}/bin/musetup-gtk
.endif
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
