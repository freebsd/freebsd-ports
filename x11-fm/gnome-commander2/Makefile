# New ports collection makefile for:	gnomem-commander
# Date created:		23 April 2002
# Whom:			Edgardo Garcia Hoeffler <edybsd@yahoo.com.ar>
#
# $FreeBSD$
#

PORTNAME=	gnome-commander
PORTVERSION=	0.9.7
CATEGORIES=	x11-fm gnome
MASTER_SITES=	http://freesoftware.fsf.org/download/gcmd/gcmd.pkg/0.9.7/
DISTNAME=	${PORTNAME}-${PORTVERSION}-2

MAINTAINER=	edybsd@yahoo.com.ar

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
.if defined(WITH_FAM)
LIB_DEPENDS=	fam.0:${PORTSDIR}/devel/fam
.endif

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomevfs gnomelibs gdkpixbuf
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
WANT_AUTOMAKE_VER=	14
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

post-patch:
.for AM in config.sub config.guess install-sh missing mkinstalldirs
	${LN} -fs ${AUTOMAKE_DIR}/${AM} ${WRKSRC}/${AM}
.endfor
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/src/gnome-cmd-data.c

.include <bsd.port.mk>
