# Created by: arved
# $FreeBSD$

PORTNAME=	x2goclient
PORTVERSION=	3.99.2.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://code.x2go.org/releases/source/x2goclient/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The x2go Qt client

LICENSE=	GPLv2

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		png15:${PORTSDIR}/graphics/png \
		cups:${PORTSDIR}/print/cups-client \
		freetype:${PORTSDIR}/print/freetype2 \
		ssh:${PORTSDIR}/security/libssh \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		xcb:${PORTSDIR}/x11/libxcb
RUN_DEPENDS=	nxproxy:${PORTSDIR}/net/nxproxy \
		x2goclient-cli:${PORTSDIR}/net/x2goclient-cli

OPTIONS_DEFINE=	LDAP DOCS
OPTIONS_DEFAULT=LDAP

USE_GETTEXT=	yes
USE_ICONV=	yes
USE_XORG=	ice sm x11 xau xdmcp xext xpm xrender
USE_QT4=	corelib gui network svg \
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
		's|Q_OS_LINUX|Q_OS_${OPSYS:U}| ; \
		 /<linux\/fs.h>/s|^|//| ; \
		 /#define USELDAP/s|^|//|'
	@${FIND} ${WRKSRC} -name "*.cpp" -or -name "*.ts" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|authentification|authentication|g'
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
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/desktop/x2goclient.desktop \
		${PREFIX}/share/applications
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
