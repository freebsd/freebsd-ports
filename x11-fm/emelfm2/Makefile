# $FreeBSD$

PORTNAME=	emelfm2
PORTVERSION=	0.9.0
CATEGORIES=	x11-fm
MASTER_SITES=	http://emelfm2.net/rel/

MAINTAINER=	mva@FreeBSD.org
COMMENT=	The gtk2 port of emelfm, a fast graphical filemanager

USE_BZIP2=	yes
USE_GNOME=	gtk20
USES=		gmake pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install

CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
MAKE_ENV=	DOC_DIR="${DOCSDIR}/" MAN_DIR="${MAN1PREFIX}/man/man1"
MAN1=		emelfm2.1

DOCFILES=	ACTIONS CONFIGURATION CREDITS GPL HACKING INSTALL LGPL NEWS \
		README SPEC TODO USAGE WARNING

OPTIONS_DEFINE=	DEBUG DOCS GAMIN THUMB TRACKER HAL NLS
OPTIONS_DEFAULT=
DEBUG_DESC=	Debugging messages
GAMIN_DESC=	Use Gamin for file monitoring
THUMB_DESC=	Thumbnail plugin
TRACKER_DESC=	Tracker-UI plugin
HAL_DESC=	Use HAL for automated device detection

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
MAK_ENV+=	DEBUG=1
.endif

.if ${PORT_OPTIONS:MGAMIN}
USES+=		fam:gamin
MAKE_ENV+=	USE_GAMIN=1
.endif

.if ${PORT_OPTIONS:MTHUMB}
LIB_DEPENDS+=	gimp:${PORTSDIR}/graphics/gimp
MAKE_ENV+=	WITH_THUMB=1
PLIST_SUB+=	THUMB=""
.else
PLIST_SUB+=	THUMB="@comment "
.endif

.if ${PORT_OPTIONS:MTRACKER}
MAKE_ENV+=	WITH_TRACKER=1
PLIST_SUB+=	TRACKER=""
.else
PLIST_SUB+=	TRACKER="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
INSTALL_TARGET+=install_i18n
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MHAL}
MAKE_ENV+=	WITH_HAL=1
LIB_DEPENDS+=	hal:${PORTSDIR}/sysutils/hal
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${DOCSDIR}
.endfor
.endif

post-patch:
# fix cross-arch compiling, which sets ${TARGET}
.for mfile in Makefile Makefile.config
	@${REINPLACE_CMD} -e 's|TARGET|BINTARGET|' ${WRKSRC}/${mfile}
.endfor

.include <bsd.port.mk>
