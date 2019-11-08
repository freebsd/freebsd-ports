# Created by: ijliao
# $FreeBSD$

PORTNAME=	pslib
PORTVERSION=	0.4.6
CATEGORIES=	print
MASTER_SITES=	SF
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C-library for generating multi page PostScript documents

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		gettext gmake gnome jpeg libtool localbase pathfix pkgconfig
USE_GNOME=	intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
LIBS+=		-lintl
INSTALL_TARGET=	install-strip

EX_DISTNAME=		pslib-examples-0.0.11
EX_WRKSRC=		${WRKDIR}/${EX_DISTNAME}

OPTIONS_DEFINE=		EXAMPLES MANPAGES NLS
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

EXAMPLES_DISTFILES=	${EX_DISTNAME}${EXTRACT_SUFX}

MANPAGES_BUILD_DEPENDS=	${LOCALBASE}/bin/docbook-to-man:textproc/docbook-to-man \
			${LOCALBASE}/bin/docbook2man:textproc/docbook-utils
MANPAGES_CONFIGURE_ENV_OFF=ac_cv_prog_DOC_TO_MAN=""

NLS_CONFIGURE_ENV_OFF=	ac_cv_header_libintl_h=no

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|@USE_NLS@|no|g' ${WRKSRC}/po/Makefile.in.in

post-install-EXAMPLES-on:
	@cd ${EX_WRKSRC} && ${RM} Makefile.unix ChangeLog CMakeLists.txt && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
