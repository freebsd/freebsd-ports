# New ports collection makefile for:	everybuddy
# Date created:			1 Mar 2000
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	everybuddy
PORTVERSION=	0.4.3
CATEGORIES=	net
MASTER_SITES=	http://www.everybuddy.com/files/

MAINTAINER=	jim@FreeBSD.org

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile \
		iconv.3:${PORTSDIR}/converters/libiconv

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
WANT_GNOME=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_BISON=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	# none
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -laudiofile"
CONFIGURE_ARGS=	--disable-arts

MAN1=		everybuddy.1

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
PKGNAMESUFFIX=	-esound
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

pre-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS:S/"//g}|g; \
		 s|-lpthreads|${PTHREAD_LIBS:S/"//g}|g; \
		 s|-D_REENTRANT -Wall -g|-D_REENTRANT ${PTHREAD_CFLAGS}|g' \
			${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^Utilitiesdir|#Utilitiesdir|g; \
		 s|^Utilities_DATA|#Utilities_DATA|g; \
		 s|[(]datadir[)]/everybuddy|(prefix)/lib/everybuddy|g; \
		 s|-module|-module -avoid-version|g'

.include <bsd.port.post.mk>
