# New ports collection makefile for:	libcdio
# Date created:				2004-04-04
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	libcdio
PORTVERSION=	0.74
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libcdio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compact Disc Input and Control Library

LIB_DEPENDS=	cddb.1:${PORTSDIR}/audio/libcddb \
		popt.0:${PORTSDIR}/devel/popt

USE_LIBTOOL_VER=15
USE_GNOME=	gnometarget pkgconfig gnomehack
USE_GMAKE=	yes
USE_ICONV=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS+=	--with-libpopt-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE} \
		--without-cd-paranoia
USE_REINPLACE=	yes
USE_PERL5_BUILD=yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -liconv"

INFO=		libcdio

post-patch:
	${REINPLACE_CMD} -e "s,freebsd5\.\*,freebsd5\.\*|freebsd6\.\*," ${WRKSRC}/configure

.include <bsd.port.mk>
