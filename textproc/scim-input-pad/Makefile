# New ports collection makefile for:	scim-input-pad
# Date created:		2005/05/06
# Whom:			chinsan	<chinsan@mail2000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	scim-input-pad
PORTVERSION=	0.1.1
PORTREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION}

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	SCIM add-on to input various symbols with on-screen pad

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
USE_GNOME=	intlhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'

.include <bsd.port.post.mk>
