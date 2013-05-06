# Created by: ijliao
# $FreeBSD$

PORTNAME=	pslib
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A C-library for generating multi page PostScript documents

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USES=		pathfix pkgconfig gettext
USE_GNOME=	intlhack
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	EXAMPLES MAN NLS
OPTIONS_DEFAULT=	MAN NLS
MAN_DESC=	Manual pages

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
EX_NAME=	pslib-examples-0.0.10
EX_WRKSRC=	${WRKDIR}/${EX_NAME}
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} ${EX_NAME}${EXTRACT_SUFX}
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

.if ${PORT_OPTIONS:MMAN}
BUILD_DEPENDS+=	${LOCALBASE}/bin/docbook-to-man:${PORTSDIR}/textproc/docbook-to-man \
		${LOCALBASE}/bin/docbook2man:${PORTSDIR}/textproc/docbook-utils
MAN3!=	${CAT} ${FILESDIR}/man3
.else
# Avoid building the manpages.
CONFIGURE_ENV+=	ac_cv_prog_DOC_TO_MAN=""
.endif

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ENV+=	ac_cv_header_libintl_h=no
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|@USE_NLS@|no|g' ${WRKSRC}/po/Makefile.in.in
.endif

post-install:
.if ${PORT_OPTIONS:MNLS}
	${MKDIR} -m 0755 ${EXAMPLESDIR}
	@${RM} -f ${EX_WRKSRC}/Makefile.unix ${EX_WRKSRC}/ChangeLog \
		${EX_WRKSRC}/CMakeLists.txt
	cd ${EX_WRKSRC} && ${PAX} -rw * ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
