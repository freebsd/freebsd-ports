# New ports collection makefile for:	ophcrack
# Date created:				14 Mar 2008
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ophcrack
PORTVERSION=	3.3.1
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Windows password cracker based on rainbow tables

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes

PLIST_FILES=	bin/ophcrack
PORTDOCS=	*

OPTIONS=	GUI	"Build GUI frontend (Qt4)"		on \
		GRAPH	"Enable graph rendering with Qwt"	off \
		DEBUG	"Make debug build"			off

.include <bsd.port.options.mk>

.if defined(WITH_GUI) || defined(WITH_GRAPH)
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build corelib gui
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

# Enable with care, will pull Qt Designer by default, which is pretty heavy
.if defined(WITH_GRAPH)
LIB_DEPENDS=	qwt.5:${PORTSDIR}/x11-toolkits/qwt5
.else
CONFIGURE_ARGS+=	--disable-graph
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
