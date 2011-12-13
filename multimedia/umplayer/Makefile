# New ports collection makefile for:	umplayer
# Date created:				2 May, 2011
# Whom:					Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	umplayer
DISTVERSION=	0.97
CATEGORIES=	multimedia audio kde
MASTER_SITES=	LOCAL/wen

MAINTAINER=	lichray@gmail.com
COMMENT=	A modern front-end for mplayer (forked from smplayer)

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USE_QT_VER=	4
QT_COMPONENTS=	gui network xml qmake_build moc_build rcc_build uic_build \
		linguist_build

ALL_TARGET=	src/umplayer

USE_XZ=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
MAKE_ARGS+=	QMAKE_OPTS="DEFINES+=NO_DEBUG_ON_CONSOLE"

MAN1=		umplayer.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|qmake|${QMAKE}|g' \
		-e 's|lrelease|${QT_PREFIX}/bin/lrelease-qt4|g' \
		-e 's|PREFIX=/usr/local|PREFIX=${PREFIX}|g' \
		-e 's,/share/man,/man,g' \
		-e 's|/doc/packages|/doc|' \
		-e 's|^.*/get_svn_revision.sh$$||' \
		${WRKSRC}/Makefile

.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e '/(install|tar).*DOC_PATH/d' \
		${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
