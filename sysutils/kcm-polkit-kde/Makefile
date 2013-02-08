# $FreeBSD$

PORTNAME=	polkit-kde
DISTVERSION=	0.0-${PORTDATE}
CATEGORIES=	sysutils kde
MASTER_SITES=	LOCAL/avilla
PKGNAMEPREFIX=	kcm-
DISTNAME=	${PORTNAME}-kcmodules-1-${PORTDATE}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Polkit-KDE configuration module

LIB_DEPENDS=	polkit-qt-agent-1:${PORTSDIR}/sysutils/polkit-qt
RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/libexec/polkit-kde-authentication-agent-1:${PORTSDIR}/sysutils/polkit-kde

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_PKGCONFIG=	build
USE_QT4=	dbus xml moc_build qmake_build rcc_build uic_build
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-kcmodules-1

PORTDATE=	20121008

post-patch:
	${REINPLACE_CMD} -e 's,/usr,${KDE4_PREFIX},' \
		-e 's,/etc,${KDE4_PREFIX}/etc,' \
		${WRKSRC}/helper/polkitkde1helper.cpp \
		${WRKSRC}/polkitactions/ActionWidget.cpp \
		${WRKSRC}/polkitconfig/kcmpolkitconfig.cpp

.include <bsd.port.mk>
