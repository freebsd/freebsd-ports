# New ports collection makefile for:   mango
# Date created:        23 March 2001
# Whom:                Roland Jesse <roland.jesse@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	mango
PORTVERSION=	0.27
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=mango
DIST_SUBDIR=	KDE

MAINTAINER=	roland.jesse@gmx.net
COMMENT=	A recipe management software

.if defined(WITH_KDE)
LIB_DEPENDS+=	kextmdi.2:${PORTSDIR}/devel/qextmdi
PKGNAMESUFFIX=	-kde
.else
LIB_DEPENDS+=	qextmdi.2:${PORTSDIR}/devel/qextmdi
PKGNAMESUFFIX=	-nokde
.endif

PLIST_FILES=	bin/mango
USE_BZIP2=	yes
USE_REINPLACE=	yes
MAKE_ENV+=	QTDIR=${QT_PREFIX} LDFLAGS="-lkextmdi"
.if defined(WITH_KDE)
USE_KDEBASE_VER=	3
.else
USE_QT_VER=	3
.endif
.if defined(MAKE_JOBS)
MAKE_ARGS+=	-j${MAKE_JOBS}
.endif

.if !defined(WITH_KDE)
pre-configure:
	@${ECHO_CMD}
	@${ECHO_CMD} "Note: Mango can be build with KDE support."
	@${ECHO_CMD} "      Please specify WITH_KDE in case you want to do so."
	@${ECHO_CMD} "      Make sure that the prerequisite QextMDI library"
	@${ECHO_CMD} "      was also installed with KDE support. The easiest"
	@${ECHO_CMD} "      way to accomplish this is to set WITH_KDE=yes in"
	@${ECHO_CMD} "      /etc/make.conf."
	@${ECHO_CMD}
.endif

do-configure:
.if defined(WITH_KDE)
	@(cd ${WRKSRC} && \
	${REINPLACE_CMD} -e 's|warn_on debug|warn_off release kde|' mango.pro)
.else
	@(cd ${WRKSRC} && \
	${REINPLACE_CMD} -e 's|warn_on debug|warn_off release|' mango.pro)
.endif
	@(cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} PREFIX=${PREFIX} \
	qmake -spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ mango.pro)

pre-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mango ${PREFIX}/bin

.include <bsd.port.mk>
