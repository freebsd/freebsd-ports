# New ports collection makefile for:	stegdetect
# Date created:			Jul 19, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	stegdetect
PORTVERSION=	0.5
CATEGORIES=	security
MASTER_SITES=	http://www.mirrors.wiretapped.net/security/steganography/stegdetect/ \
		http://www.outguess.org/

MAINTAINER=	markp@FreeBSD.org

.if !defined(WITHOUT_X11)
BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent
.endif

# Note: stegdetect includes a modified version of jpeg-6b linked statically
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
MAN1=		stegdetect.1 stegbreak.1

.if defined(WITHOUT_X11)
PLIST_SUB+=	X11="@comment "
.else
USE_GNOMENG=	yes
USE_GNOME=	gtk12
CONFIGURE_ENV=	PATH_GTKCONFIG="${GTK_CONFIG}"
PLIST_SUB+=	X11=""
.endif

post-patch:
	@${PERL} -pi -e 's@\$$\(JPEGLIB\)@\$$\(JPEGLIB\) \-lcrypto@' \
		${WRKSRC}/Makefile.in
.if defined(WITHOUT_X11)
	@${PERL} -pi -e 's/gtk-config//g' ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
