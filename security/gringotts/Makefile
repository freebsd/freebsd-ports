# New ports collection makefile for:	gringotts
# Date created:				02 July 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gringotts
PORTVERSION=	1.2.1
CATEGORIES=	security
MASTER_SITES=	http://devel.pluto.linux.it/projects/Gringotts/current/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	anders@FreeBSD.org

LIB_DEPENDS=	gringotts.2:${PORTSDIR}/security/libgringotts \
		gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20 \
		popt.0:${PORTSDIR}/devel/popt

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOMENG=	yes
USE_REINPLACE=	yes
WANT_GNOME=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS+=	--disable-env-check

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomehier}!=""
USE_GNOME+=	gnomehier
.endif

post-patch:
	${REINPLACE_CMD} -e "s|md5sum|md5|g" ${WRKSRC}/Makefile.in
.if ${HAVE_GNOME:Mgnomehier}==""
	${REINPLACE_CMD} -E "s|(MAKE.*AM_MAKEFLAGS.*install-exec-am).*|\1|" \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
