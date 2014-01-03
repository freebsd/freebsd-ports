# Created by: arved
# $FreeBSD$

PORTNAME=	x2goclient
PORTVERSION=	4.0.1.2
CATEGORIES=	net
MASTER_SITES=	http://code.x2go.org/releases/source/x2goclient/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt client for the X2Go system

LICENSE=	GPLv2

# Avoid clash with libssh from base
BUILD_DEPENDS=	${LOCALBASE}/lib/libssh.so:${PORTSDIR}/security/libssh
LIB_DEPENDS=	libcups.so:${PORTSDIR}/print/cups-client \
		libssh.so:${PORTSDIR}/security/libssh
RUN_DEPENDS=	nxproxy:${PORTSDIR}/net/nxproxy \
		x2goclient-cli:${PORTSDIR}/net/x2goclient-cli

OPTIONS_DEFINE=	LDAP DOCS
OPTIONS_DEFAULT=LDAP

USES=		qmake
USE_XORG=	xpm
USE_QT4=	gui network svg \
		linguist_build moc_build rcc_build uic_build
QMAKE_ARGS=	QMAKE_LRELEASE="${LRELEASE}"
INSTALLS_ICONS=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CFLAGS+=	-DUSELDAP
QMAKE_ARGS+=	LIBS+="-lX11 -lXpm -lcups -lldap"
.else
QMAKE_ARGS+=	LIBS+="-lX11 -lXpm -lcups"
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.cpp" -or -name "*.h" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|Q_OS_LINUX|Q_OS_UNIX| ; \
		 /<linux\/fs.h>/s|^|//| ; \
		 /#define USELDAP/s|^|//|'

pre-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} compiler_TSQM_make_all)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} x2goclient \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} x2goclient.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	(cd ${WRKSRC}/desktop && ${INSTALL_DATA} x2goclient.desktop \
		${STAGEDIR}${DESKTOPDIR})
.for i in 16x16 32x32 48x48 64x64 128x128
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}/apps
	(cd ${WRKSRC}/icons/${i} && ${INSTALL_DATA} x2goclient.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}/apps)
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
	(cd ${WRKSRC}/icons && ${INSTALL_DATA} x2goclient.xpm \
		${STAGEDIR}${DATADIR}/icons)
.for i in x2goclient.png x2gosession.png
	(cd ${WRKSRC}/icons/128x128 && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DATADIR}/icons)
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} HOWTO.GPGCARD ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
