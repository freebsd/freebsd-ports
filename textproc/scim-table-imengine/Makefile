# New ports collection makefile for:    scim-table-imengine
# Date created:		01 March 2005
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	scim-table-imengine
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=scim
DISTNAME=	scim-tables-${PORTVERSION}

MAINTAINER=	gaoj@cpsc.ucalgary.ca
COMMENT=	SCIM table based input method engine

LIB_DEPENDS=	scim-1.0.8:${PORTSDIR}/textproc/scim

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=	15
USE_GNOME=	intlhack

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
EXTRA_PATCHES=	${FILESDIR}/extrapatch-4-stable-src-Makefile.in
.endif

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"

post-install:
.if ${OSVERSION} < 500035
	@${INSTALL_SCRIPT} ${FILESDIR}/scim-make-table.sh ${PREFIX}/bin/scim-make-table
.endif
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.post.mk>
