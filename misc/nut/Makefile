# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	nut
PORTVERSION=	18.4
CATEGORIES=	misc
MASTER_SITES=	SF
PKGNAMEPREFIX=	health-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nutrition software to record what you eat

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	FLTK DOCS
FLTK_DESC=	Install FLTK GUI

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}

MAN1=		${PORTNAME}.1
PORTDOCS=	CREDITS README nut.html
PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/FOOD_DES.txt \
		%%DATADIR%%/NUT_DATA.txt %%DATADIR%%/WEIGHT.lib \
		%%DATADIR%%/WEIGHT.txt %%DATADIR%%/sr25.nut
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFLTK}
LIB_DEPENDS+=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		fltk_images:${PORTSDIR}/x11-toolkits/fltk \
		xcb:${PORTSDIR}/x11/libxcb
USE_XORG+=	x11 xau xdmcp xext xft xinerama xrender
MAKE_ENV+=	HAVE_FLTK=1 FLTK_NUT="fltk/Nut"
PLIST_FILES+=	bin/Nut
DESKTOP_ENTRIES="Nut" "${COMMENT}" "" "Nut" \
		"Science;Biology;MedicalSoftware;" "false"
.else
MAKE_ENV+=	HAVE_FLTK=0 FLTK_NUT=""
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(prefix)/lib/nut|${DATADIR}| ; \
		 s|^HAVE_FLTK|#HAVE_FLTK| ; \
		 s|^FLTK_NUT|#FLTK_NUT| ; \
		 s|^CC =|CC ?=| ; \
		 s|^CXX =|CXX ?=| ; \
		 s|^CFLAGS :=|CFLAGS +=| ; \
		 s|-ansi -pedantic|| ; \
		 s|$$(OPT)|| ; \
		 s|ldstaticflags|ldflags| '

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MFLTK}
	${INSTALL_PROGRAM} ${WRKSRC}/fltk/Nut ${PREFIX}/bin
.endif
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/raw.data && ${COPYTREE_SHARE} . ${DATADIR})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
