# New ports collection makefile for:    scim-table-imengine
# Date created:		01 March 2005
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	scim-table-imengine
PORTVERSION=	0.5.7
PORTREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	SF/scim/scim-tables/${PORTVERSION}
DISTNAME=	scim-tables-${PORTVERSION}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	SCIM table based input method engine

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	intlhack
USE_GETTEXT=	yes

MAN1=		scim-make-table.1

.include <bsd.port.pre.mk>

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl" \
		PREFIX="${PREFIX}"

PLIST_SUB=	SKIM="@comment "

pre-fetch:
	@${ECHO_MSG} Define WITH_SKIM to enable skim support

.if exists(${LOCALBASE}/bin/skim)
WITH_SKIM=	yes
pre-patch:
	@${ECHO_MSG} Skim is detected, support enabled.
.endif

.if defined(WITH_SKIM)
BUILD_DEPENDS+=	skim:${PORTSDIR}/textproc/skim
CONFIGURE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB=	SKIM=""
USE_AUTOTOOLS=	libtool:22
post-patch:
	@${REINPLACE_CMD} -e "/^DIST_SUBDIRS/s/$$/ skim/" \
		-e "/^@SCIM_TABLES_ENABLE_SKIM_SUPPORT_TRUE@SKIM_SUBDIR =/s/$$/ skim/" \
		${WRKSRC}/Makefile.in
post-configure:
	${REINPLACE_CMD} \
		-e 's,$$(top_builddir)/libtool --silent,${LIBTOOL},' \
		${WRKSRC}/skim/Makefile ${WRKSRC}/skim/setupui/Makefile
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.post.mk>
