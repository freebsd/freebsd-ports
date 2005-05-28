# New ports collection makefile for:   dar
# Date created:        3 January 2004
# Whom:                Edson Brandi <ebrandi@fugspbr.org>
#
# $FreeBSD$
#

PORTNAME=	dar
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	ebrandi@fugspbr.org
COMMENT=	A full featured command-line backup tool, aimed for disks

INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes

CPPFLAGS+=	-DHAVE_DECL_GETOPT=0

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
EXTRA_PATCHES=  ${PATCHDIR}/extra-patch-src-libdar-integers.hpp
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-libintl-prefix=${PREFIX}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		dar.1 dar_cp.1 dar_manager.1 dar_slave.1 dar_xform.1

post-patch:
	@${REINPLACE_CMD} -Ee 's,(_nl_expand_alias) \(0\),\1 (),g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
