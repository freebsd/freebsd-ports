# New ports collection makefile for:	blam
# Date created:				20040812
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.22 2006/10/26 05:32:53 tmclau02 Exp $
#

PORTNAME=	blam
PORTVERSION=	1.8.4
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	http://www.cmartin.tk/blam/

MAINTAINER=	bsd-sharp@googlegroups.com
COMMENT=	Mono based RSS feed reader

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gecko-sharp-2.0.pc:${PORTSDIR}/www/gecko-sharp20
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gecko-sharp-2.0.pc:${PORTSDIR}/www/gecko-sharp20

USE_GECKO=	firefox mozilla
USE_GNOME=	gnomeprefix gnomehack intlhack intltool libgnomeui gnomesharp20
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mozilla=${GECKO}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	blam.1

GCONF_SCHEMAS=	blam.schemas

post-patch:
	@${REINPLACE_CMD} 's|img src="|img src="file://${PREFIX}/share/blam/themes/blam/|g' \
		${WRKSRC}/themes/blam/theme.html
	@${REINPLACE_CMD} 's|img src="|img src="file://${PREFIX}/share/blam/themes/pimped/|g' \
		${WRKSRC}/themes/pimped/theme.html


.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
