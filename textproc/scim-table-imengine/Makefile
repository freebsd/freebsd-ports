# Created by: Jie Gao <gaoj@cpsc.ucalgary.ca>
# $FreeBSD$

PORTNAME=	scim-table-imengine
PORTVERSION=	0.5.10
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/scim/scim-tables/${PORTVERSION}
DISTNAME=	scim-tables-${PORTVERSION}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	SCIM table based input method engine

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS=	scim:${PORTSDIR}/textproc/scim

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_GNOME=	intlhack
USES=		gettext gmake pkgconfig

MAN1=		scim-make-table.1

.include <bsd.port.pre.mk>

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__

CONFIGURE_ENV+=	PREFIX="${PREFIX}"
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

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
USE_AUTOTOOLS=	libtool
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
