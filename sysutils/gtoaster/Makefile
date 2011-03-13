# New ports collection makefile for:	gtoaster
# Date created:				28 September 2000
# Whom:					eric
#
# $FreeBSD$
#

PORTNAME=	gtoaster
PORTVERSION=	1.0.b6
PORTREVISION=	6
PORTEPOCH=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://gnometoaster.rulez.org/archive/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.b/Beta/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical cd cooking interface

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/gtoaster
USE_GETTEXT=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack gnometarget gtk12
USE_GMAKE=	yes
USE_CDRTOOLS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
PKGNAMESUFFIX=	-gnome
USE_GNOME+=	gnomelibs
.else
CONFIGURE_ARGS+=	--without-gnome
.endif

.if ${HAVE_GNOME:Morbit}!=""
USE_GNOME+=	orbit
.else
CONFIGURE_ARGS+=	--without-orbit
.endif

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
.else
CONFIGURE_ARGS+=	--without-esd
.endif

post-extract:
	@${RM} -f ${WRKSRC}/config.guess
	@${TOUCH} ${WRKSRC}/config.guess

post-patch:
	${REINPLACE_CMD} -e 's, -pthread, ${PTHREAD_LIBS},g' \
		${WRKSRC}/configure
.include <bsd.port.post.mk>
