# New ports collection makefile for:	scim-input-pad
# Date created:		2005/05/06
# Whom:			chinsan	<chinsan@mail2000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	scim-input-pad
PORTVERSION=	0.1.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=scim

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	SCIM add-on to input various symbols with on-screen pad

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	intlhack
USE_LIBTOOL_VER=	15
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"

.include <bsd.port.pre.mk>

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'

.include <bsd.port.post.mk>
