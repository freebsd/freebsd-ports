# ex:ts=8
# New ports collection makefile for:	gfontview
# Date created:			Jul 9, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gfontview
PORTVERSION=	0.5.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	t1:${PORTSDIR}/devel/t1lib \
		ungif:${PORTSDIR}/graphics/libungif \
		intl:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes
USE_FREETYPE=	yes
USE_GTK=	yes
USE_GNOME=	yes
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-libungif

post-patch:
	@${PERL} -pi -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
