# Created by: arved
# $FreeBSD$

PORTNAME=	x2goclient
PORTVERSION=	4.0.5.1
CATEGORIES=	net
MASTER_SITES=	http://code.x2go.org/releases/source/x2goclient/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt client for the X2Go system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

# Avoid clash with libssh from base
BUILD_DEPENDS=	${LOCALBASE}/lib/libssh.so:security/libssh
LIB_DEPENDS=	libcups.so:print/cups \
		libssh.so:security/libssh
RUN_DEPENDS=	nxproxy:net/nxproxy \
		x2goclient-cli:net/x2goclient-cli

USES=		qmake
USE_XORG=	xpm
USE_QT4=	gui network svg \
		linguisttools_build moc_build rcc_build uic_build
QMAKE_ARGS=	QMAKE_LRELEASE="${LRELEASE}"

OPTIONS_DEFINE=		DOCS LDAP
OPTIONS_DEFAULT=	LDAP

LDAP_USE=		OPENLDAP=yes
LDAP_CFLAGS=		-DUSELDAP
LDAP_QMAKE_ON=		LIBS+="-lX11 -lXpm -lcups -lldap"
LDAP_QMAKE_OFF=		LIBS+="-lX11 -lXpm -lcups"

post-patch:
	@${FIND} ${WRKSRC}/src -name "*.cpp" -or -name "*.h" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|Q_OS_LINUX|Q_OS_UNIX| ; \
		 /<linux\/fs.h>/s|^|//| ; \
		 /#define USELDAP/s|^|//| ; \
		 s|/usr/local/bin|${LOCALBASE}/bin|'

pre-build:
	@(cd ${WRKSRC} && ${DO_MAKE_BUILD} compiler_TSQM_make_all)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x2goclient ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/x2goclient.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/desktop/x2goclient.desktop \
		${STAGEDIR}${DESKTOPDIR}
.for i in 16x16 32x32 48x48 64x64 128x128
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}/apps
	${INSTALL_DATA} ${WRKSRC}/res/img/icons/${i}/x2goclient.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}/apps
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/res/img/icons/x2goclient.xpm \
		${STAGEDIR}${DATADIR}/icons
.for i in x2goclient.png x2gosession.png
	${INSTALL_DATA} ${WRKSRC}/res/img/icons/128x128/${i} \
		${STAGEDIR}${DATADIR}/icons
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/HOWTO.GPGCARD ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
