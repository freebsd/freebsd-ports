# Created by: arved
# $FreeBSD$

PORTNAME=	x2goclient
PORTVERSION=	4.0.0.1
CATEGORIES=	net
MASTER_SITES=	http://code.x2go.org/releases/source/x2goclient/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt client for the X2Go system

LICENSE=	GPLv2

LIB_DEPENDS=	cups:${PORTSDIR}/print/cups-client \
		ssh:${PORTSDIR}/security/libssh
RUN_DEPENDS=	nxproxy:${PORTSDIR}/net/nxproxy \
		x2goclient-cli:${PORTSDIR}/net/x2goclient-cli

OPTIONS_DEFINE=	LDAP DOCS
OPTIONS_DEFAULT=LDAP

USE_XORG=	xpm
USE_QT4=	gui network svg \
		linguist_build moc_build qmake_build rcc_build uic_build
QMAKEFLAGS=	QMAKE_LRELEASE="${QT_PREFIX}/bin/lrelease-qt4"
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		x2goclient.1

PORTSCOUT=	limit:\^3\.0

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CFLAGS+=	-DUSELDAP
QMAKEFLAGS+=	LIBS+="-lX11 -lXpm -lcups -lldap"
.else
QMAKEFLAGS+=	LIBS+="-lX11 -lXpm -lcups"
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.cpp" -or -name "*.h" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|Q_OS_LINUX|Q_OS_UNIX| ; \
		 /<linux\/fs.h>/s|^|//| ; \
		 /#define USELDAP/s|^|//|'
	@${REINPLACE_CMD} -e \
		'/MACOSX/s|^|#|' ${WRKSRC}/x2goclient.pro
	@${REINPLACE_CMD} -e \
		's|/usr/bin/||' ${WRKSRC}/desktop/x2goclient.desktop

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS}

pre-build:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} compiler_TSQM_make_all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x2goclient ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/x2goclient.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/desktop/x2goclient.desktop \
		${DESKTOPDIR}
.for dir in 16x16 32x32 64x64 128x128
	@${MKDIR} ${PREFIX}/share/icons/hicolor/${dir}/apps
	${INSTALL_DATA} ${WRKSRC}/icons/${dir}/x2goclient.png \
		${PREFIX}/share/icons/hicolor/${dir}/apps
.endfor
	@${MKDIR} ${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/x2goclient.xpm ${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/128x128/x2goclient.png ${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/128x128/x2gosession.png ${DATADIR}/icons
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/HOWTO.GPGCARD ${DOCSDIR}
.endif

.include <bsd.port.mk>
