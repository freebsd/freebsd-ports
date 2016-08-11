# Created by: ijliao
# $FreeBSD$

PORTNAME=	pslib
PORTVERSION=	0.4.5
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	mva@FreeBSD.org
COMMENT=	C-library for generating multi page PostScript documents

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		gettext gmake jpeg libtool pathfix pkgconfig
USE_GNOME=	intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lintl
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	EXAMPLES MANPAGES NLS
OPTIONS_DEFAULT=	MANPAGES

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
EX_NAME=	pslib-examples-0.0.10
EX_WRKSRC=	${WRKDIR}/${EX_NAME}
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} ${EX_NAME}${EXTRACT_SUFX}
.endif

.if ${PORT_OPTIONS:MMANPAGES}
BUILD_DEPENDS+=	${LOCALBASE}/bin/docbook-to-man:textproc/docbook-to-man \
		${LOCALBASE}/bin/docbook2man:textproc/docbook-utils
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
	${MKDIR} -m 0755 ${STAGEDIR}${EXAMPLESDIR}
	@${RM} -f ${EX_WRKSRC}/Makefile.unix ${EX_WRKSRC}/ChangeLog \
		${EX_WRKSRC}/CMakeLists.txt
	cd ${EX_WRKSRC} && ${PAX} -rw * ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
