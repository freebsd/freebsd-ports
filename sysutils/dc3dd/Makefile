# New ports collection makefile for:   dc3dd
# Date created:        15 February 2011
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dc3dd
PORTVERSION=	7.0.0
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A dd program useful for computer forensics

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="${LIBS} -L${LOCALBASE}/lib"

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

MAN1=		dc3dd.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
