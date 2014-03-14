# $FreeBSD$

PORTNAME=	gdis
PORTVERSION=	0.90
CATEGORIES=	science
MASTER_SITES=	SF
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display and manipulation of isolated molecules and periodic systems

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext

OPTIONS_DEFINE=	DOCS

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
USE_GL=		glu
USE_GNOME=	gtk20
USES=		gmake pkgconfig
MAKEFILE=	GNUmakefile
LDFLAGS+=	-lm

PORTDOCS=	CHANGELOG README TODO
PLIST_FILES=	bin/gdis %%DATADIR%%/gdis.elements %%DATADIR%%/gdis.library \
		%%DATADIR%%/gdis.manual share/pixmaps/gdis.xpm
PLIST_DIRS=	%%DATADIR%%

DESKTOP_ENTRIES="GDIS" "Molecular modelling GUI" \
		"${PREFIX}/share/pixmaps/gdis.xpm" "${PORTNAME}" "" true

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|"\(gdis.elements\)|"../share/gdis/\1| ; \
		 s|"\(gdis.library\)|"../share/gdis/\1|' ${WRKSRC}/gdis.h
	@${REINPLACE_CMD} -e \
		's|"\(gdis.manual\)|"../share/gdis/\1|' ${WRKSRC}/gui_help.c

do-configure:
	@${ECHO_CMD} -n \
		> ${WRKSRC}/${MAKEFILE}
	@${ECHO_CMD} 'USE_GUI=YES' \
		>> ${WRKSRC}/${MAKEFILE}
	@${ECHO_CMD} 'USE_GRISU=NO' \
		>> ${WRKSRC}/${MAKEFILE}
	@${ECHO_CMD} 'include makefile.src' \
		>> ${WRKSRC}/${MAKEFILE}
	@${ECHO_CMD} 'CFLAGS:=$$(CFLAGS) -DWITH_GUI' \
		>> ${WRKSRC}/${MAKEFILE}
	@${ECHO_CMD} \
		>> ${WRKSRC}/${MAKEFILE}
	@${ECHO_CMD} 'INCS=`pkg-config --cflags gtkglext-1.0`' \
		>> ${WRKSRC}/${MAKEFILE}
	@${ECHO_CMD} 'LIBS=`pkg-config --libs gtkglext-1.0` -lgthread-2.0' \
		>> ${WRKSRC}/${MAKEFILE}
	@${ECHO_CMD} 'OBJ=$$(SRC:.c=.o)' \
		>> ${WRKSRC}/${MAKEFILE}
	@${ECHO_CMD} \
		>> ${WRKSRC}/${MAKEFILE}
	@${ECHO_CMD} 'all: gdis' \
		>> ${WRKSRC}/${MAKEFILE}
	@${ECHO_CMD} 'gdis: $$(OBJ)' \
		>> ${WRKSRC}/${MAKEFILE}
	@${ECHO_CMD} '	$$(CC) $$(OBJ) $$(LDFLAGS) -o gdis $$(LIBS)' \
		>> ${WRKSRC}/${MAKEFILE}
	@${ECHO_CMD} '.c.o:' \
		>> ${WRKSRC}/${MAKEFILE}
	@${ECHO_CMD} '	$$(CC) $$(CFLAGS) -c $$< $$(INCS)' \
		>> ${WRKSRC}/${MAKEFILE}
	@(cd ${WRKSRC} && ${SED} -e 's|logo_right_81|gdis|' \
		< logo_right.xpm > gdis.xpm)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} gdis ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_DATA} gdis.xpm ${PREFIX}/share/pixmaps)
	@${MKDIR} ${DATADIR}
.for i in gdis.elements gdis.library gdis.manual
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DATADIR})
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
