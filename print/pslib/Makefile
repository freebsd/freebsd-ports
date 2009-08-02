# ex:ts=8
# Ports collection makefile for:	pslib
# Date created:			Jul 13, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pslib
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A C-library for generating multi page PostScript documents

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_GNOME=	gnomehack gnometarget intlhack pkgconfig
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
USE_LDCONFIG=	yes

OPTIONS=	EXAMPLES	"Install additional examples" On \
		MAN		"Install manual pages" On \
		NLS		"Native language support" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EXAMPLES)
EX_NAME=	pslib-examples-0.0.9
EX_WRKSRC=	${WRKDIR}/${EX_NAME}
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} ${EX_NAME}${EXTRACT_SUFX}
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

.if !defined(WITHOUT_MAN)
BUILD_DEPENDS+=	${LOCALBASE}/bin/docbook-to-man:${PORTSDIR}/textproc/docbook-to-man \
		${LOCALBASE}/bin/docbook2man:${PORTSDIR}/textproc/docbook-utils
MAN3!=	${CAT} ${FILESDIR}/man3
.else
# Avoid building the manpages.
CONFIGURE_ENV+=	ac_cv_prog_DOC_TO_MAN=""
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ENV+=	ac_cv_header_libintl_h=no
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e 's|@USE_NLS@|no|g' ${WRKSRC}/po/Makefile.in.in
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} -m 0755 ${EXAMPLESDIR}
	@${RM} -f ${EX_WRKSRC}/Makefile.unix ${EX_WRKSRC}/ChangeLog \
		${EX_WRKSRC}/CMakeLists.txt
	cd ${EX_WRKSRC} && ${PAX} -rw * ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
