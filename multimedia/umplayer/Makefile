# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	umplayer
DISTVERSION=	0.97
PORTREVISION=	1
CATEGORIES=	multimedia audio kde
MASTER_SITES=	LOCAL/wen

MAINTAINER=	lichray@gmail.com
COMMENT=	Modern front-end for MPlayer (fork of SMPlayer)

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

USES=		gmake qmake
USE_XZ=		yes
USE_QT4=	gui network xml moc_build rcc_build uic_build \
		linguist_build
INSTALLS_ICONS=	yes
MAKE_ARGS+=	PREFIX=${PREFIX} DESTDIR=${STAGEDIR}
QMAKE_ARGS+=	"DEFINES+=NO_DEBUG_ON_CONSOLE"
ALL_TARGET=	src/umplayer
CONFIGURE_WRKSRC=	${WRKSRC}/src

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's| make| $$(MAKE)|' \
		-e 's|cd src|(&| ; /cd src/s|$$|)|' \
		-e 's|&& $$(QMAKE) $$(QMAKE_OPTS)||' \
		-e 's|lrelease|${LRELEASE}|' \
		-e 's|/share/man|/man|' \
		-e 's|/doc/packages|/doc|' \
		-e 's|^.*/get_svn_revision.sh$$||' \
			${WRKSRC}/Makefile
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -E -e '/(install|tar).*DOC_PATH/d' \
		${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
