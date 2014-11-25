# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	egueb
PORTVERSION=	20121003
CATEGORIES=	www enlightenment
MASTER_SITES=	http://files.roorback.net/e17/extra/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Egueb provides support for www standards

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex

DIST_SUBDIR=	e17
GNU_CONFIGURE=	yes
USES=		bison gmake pathfix pkgconfig tar:bzip2
USE_EFL=	eina enesim ender etch libtool_hack
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-static

BROKEN=		Don't build with EFL 1.11
DEPRECATED=	Unused by EFL 1.11
EXPIRATION_DATE=2014-12-31

post-patch:
	@${REINPLACE_CMD} -e "s|@LEX@|${LOCALBASE}/bin/flex|" \
		${WRKSRC}/ecss/lib/Makefile.in

.include <bsd.port.mk>
