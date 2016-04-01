# $FreeBSD$

PORTNAME=	polkit-kde
DISTVERSION=	0.0-${PORTDATE}
PORTREVISION=	3
CATEGORIES=	sysutils kde
MASTER_SITES=	LOCAL/avilla
PKGNAMEPREFIX=	kcm-
DISTNAME=	${PORTNAME}-kcmodules-1-${PORTDATE}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Polkit-KDE configuration module

LIB_DEPENDS=	libpolkit-qt-agent-1.so:sysutils/polkit-qt
RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/libexec/polkit-kde-authentication-agent-1:sysutils/polkit-kde

USE_KDE4=	kdelibs kdeprefix automoc4
USE_QT4=	dbus xml moc_build qmake_build rcc_build uic_build
USES=		cmake gmake pkgconfig tar:bzip2
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
