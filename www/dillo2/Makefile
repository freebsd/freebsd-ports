# New ports collection makefile for:   dillo
# Date created:        23 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#
# Tunables:
# WITH_DILLO_SSL: enable experimental SSL support
#

PORTNAME=	dillo
PORTVERSION=	0.8.5
CATEGORIES=	www
MASTER_SITES=	http://www.dillo.org/download/

MAINTAINER=	tmseck@netcologne.de
COMMENT=	A fast, small graphical Web browser built upon GTK+

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GNOME=	gnometarget gtk12
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-ipv6 --libdir=${PREFIX}/libexec

.if defined(WITH_DILLO_SSL)
CONFIGURE_ARGS+=	--enable-ssl
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g ; \
		 s|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|dillorc|dillorc.sample|g' ${WRKSRC}/Makefile.in
	@${CP} ${WRKSRC}/dillorc ${WRKSRC}/dillorc.sample

pre-configure:
.if !defined(WITH_DILLO_SSL)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   You can enable dillo's experimental SSL support by specifing"
	@${ECHO_CMD} "   WITH_DILLO_SSL=yes in your make environment or on the"
	@${ECHO_CMD} "   commandline."
	@${ECHO_CMD} ""
.endif

.include <bsd.port.mk>
