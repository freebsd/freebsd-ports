# New ports collection makefile for:	museekplus
# Date created:				06 Aug 2006
# Whom:					Stefan Walter <stefan@FreeBSD.org>
#
# $FreeBSD$
#
# This port's behaviour can be adjusted by defining the following variables:
#
# WITHOUT_MUSEEQ        - build without museeq, the Qt frontend
# WITHOUT_QSA           - build museeq without scripting support
# WITH_DEBUG            - build with debugging messages
# WITH_OPTIMIZED_CFLAGS - build with optimizations and exclude debug symbols

PORTNAME=	museekplus
PORTVERSION=	0.1.12
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	museek-plus
DISTNAME=	museek+-${PORTVERSION}

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	SoulSeek client with separate terminal and Qt based interface

LIB_DEPENDS=	xml\\+\\+:${PORTSDIR}/textproc/libxml++26 \
		vorbis:${PORTSDIR}/audio/libvorbis
BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13

BROKEN=		Does not build

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_SCONS=	yes
USE_FAM=	yes

SCONS_ARGS=	QTDIR=${QT_PREFIX} QT_LIB=qt-mt PREFIX=${PREFIX} VORBIS=yes
DATADIR=	share/museek

MAN1=		muscan.1 muscand.1 museekd.1 musetup.1 musetup-gtk.1 mulog.1 \
		museekcontrol.1 mucous.1

.if defined(WITHOUT_MUSEEQ)
SCONS_ARGS+=	MUSEEQ=no
PLIST_SUB+=	MUSEEQ="@comment "
.else
USE_QT_VER=	3
SCONS_ARGS+=	MUSEEQ=yes
PLIST_SUB+=	MUSEEQ=""
MAN1+=		museeq.1
.if defined(WITHOUT_QSA)
SCONS_ARGS+=	QSA=no
.else
SCONS_ARGS+=	QSA=yes
LIB_DEPENDS+=	qsa:${PORTSDIR}/devel/qsa
.endif
.endif

.if defined(WITH_DEBUG)
SCONS_ARGS+=	MULOG="cycle,debug"
.else
SCONS_ARGS+=	MULOG=""
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
SCONS_ARGS+=	RELEASE=yes
.else
SCONS_ARGS+=	RELEASE=no
.endif

pre-everything::
.if !defined(WITHOUT_MUSEEQ)
	@${ECHO_MSG} "Define WITHOUT_MUSEEQ to build without the Qt frontend"
.endif
.if !defined(WITH_DEBUG)
	@${ECHO_MSG} "Define WITH_DEBUG to build with debugging messages"
.endif
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "Define WITH_OPTIMIZED_CFALGS to build with optmizations"
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "s,%%PYTHONPREFIX_SITELIBDIR%%,${PYTHONPREFIX_SITELIBDIR},g"\
		${WRKSRC}/Mucipher/python/SConscript \
		${WRKSRC}/mucous/pymucous/SConscript \
		${WRKSRC}/pymuseekd/museek/SConscript

post-install:
	@${REINPLACE_CMD} -i "" -e "s,/usr/bin/python,${PYTHON_CMD},g" \
		${PREFIX}/bin/mucous
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
BROKEN=		Does not compile on amd64
.endif

.if (${OSVERSION} < 500000)
IGNORE=		does not compile on systems < 5.x (needs wstring support)
.endif

.include <bsd.port.post.mk>
