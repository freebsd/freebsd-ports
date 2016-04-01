# $FreeBSD$

PORTNAME=	lingoteach
PORTVERSION=	0.3.9
PORTREVISION=	15
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/OldFiles:src
DISTFILES=	${PORTNAME}-ui-${PORTVERSION}.tar.gz:src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Language teaching program with sound

LIB_DEPENDS=	liblingoteach.so:textproc/liblingoteach

WRKSRC=		${WRKDIR}/${PORTNAME}-ui-${PORTVERSION}

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig libtool

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib `pkg-config --libs gmodule-2.0`

# sound version
SOUNDV=		0.3.9

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	NLS SOUND DEBUG DOCS
OPTIONS_SUB=	yes

SOUND_DESC=	Download additional sounds
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
DEBUG_CONFIGURE_ENABLE=	debug

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOUND}
MASTER_SITES+=	SF/${PORTNAME}/${PORTNAME}-sound/${SOUNDV}:sound
DISTFILES+=	${PORTNAME}-sound-${SOUNDV}.tar.gz:sound
.endif

post-patch::
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|^SUBDIRS = intl src po data doc|SUBDIRS = src po data doc|g' \
	    ${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e 's|^SUBDIRS = intl src po data doc|SUBDIRS = src po data|g' \
	    ${WRKSRC}/Makefile.in
.endif

.if ${PORT_OPTIONS:MSOUND}
post-install::
	cd ${WRKDIR}/${PORTNAME}-sound-${SOUNDV}/data; \
		${RM} -f Make*; \
		${CP} -R ${WRKDIR}/${PORTNAME}-sound-${SOUNDV}/data \
		${STAGEDIR}${DATADIR};
.endif

.include <bsd.port.mk>
