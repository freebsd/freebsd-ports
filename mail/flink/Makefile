# New ports collection makefile for:	flink
# Date created:				27 Aug 2002
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	flink
PORTVERSION=	0.3.2
CATEGORIES=	mail gnome
MASTER_SITES=	http://flink.leyman.nu/

MAINTAINER=	rael@vectorstar.net

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack libpanel
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=	flink.1

DOCS=	AUTHORS COPYING INSTALL NEWS README ChangeLog

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ;' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
