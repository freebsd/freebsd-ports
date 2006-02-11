# New ports collection makefile for:    scim-table-imengine
# Date created:		01 March 2005
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	scim-table-imengine
PORTVERSION=	0.5.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=scim
DISTNAME=	scim-tables-${PORTVERSION}

MAINTAINER=	gaoj@cpsc.ucalgary.ca
COMMENT=	SCIM table based input method engine

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	intlhack

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
EXTRA_PATCHES=	${FILESDIR}/extrapatch-4-stable-src-Makefile.in
.endif

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"

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
post-patch:
	@${REINPLACE_CMD} -e "/^DIST_SUBDIRS/s/$$/ skim/" \
		-e "/^@SCIM_TABLES_ENABLE_SKIM_SUPPORT_TRUE@SKIM_SUBDIR =/s/$$/ skim/" \
		${WRKSRC}/Makefile.in
.endif

post-install:
.if ${OSVERSION} < 500035
	@${INSTALL_SCRIPT} ${FILESDIR}/scim-make-table.sh ${PREFIX}/bin/scim-make-table
.endif
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.post.mk>
