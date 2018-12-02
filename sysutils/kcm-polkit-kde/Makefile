# $FreeBSD$

PORTNAME=	polkit-kde
DISTVERSION=	0.0-${PORTDATE}
PORTREVISION=	6
CATEGORIES=	sysutils kde
MASTER_SITES=	LOCAL/avilla
PKGNAMEPREFIX=	kcm-
DISTNAME=	${PORTNAME}-kcmodules-1-${PORTDATE}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Polkit-KDE configuration module

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libpolkit-qt-agent-1.so:sysutils/polkit-qt@qt4
RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/libexec/polkit-kde-authentication-agent-1:sysutils/polkit-kde

USES=		cmake kde:4 pkgconfig qt:4 tar:bzip2
USE_KDE=	kdelibs automoc4
USE_QT=		dbus xml moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-kcmodules-1

PORTDATE=	20121008

post-patch:
	${REINPLACE_CMD} -e 's,/usr,${KDE_PREFIX},' \
		-e 's,/etc,${KDE_PREFIX}/etc,' \
		${WRKSRC}/helper/polkitkde1helper.cpp \
		${WRKSRC}/polkitactions/ActionWidget.cpp \
		${WRKSRC}/polkitconfig/kcmpolkitconfig.cpp

.include <bsd.port.mk>
