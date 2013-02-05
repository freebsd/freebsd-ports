# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$
#
# Tunables:
# WITH_DILLO_SSL: enable experimental SSL support
#

PORTNAME=	dillo
PORTVERSION=	0.8.6
PORTREVISION=	7
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.dillo.org/download/

MAINTAINER=	tmseck@netcologne.de
COMMENT=	A fast, small graphical Web browser built upon GTK+

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-cookies --enable-threaded-dns \
		--libdir=${PREFIX}/libexec \
		--disable-dlgui
.if !defined(WITHOUT_DILLO_IPV6) && !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_DILLO_SSL)
CONFIGURE_ARGS+=	--enable-ssl
EXTRA_PATCHES+=	${PATCHDIR}/enable-ssl.patch
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--disable-ssl
.endif

CONFLICTS=	dillo-i18n-*[0-9]* \
		dillo-[2-9]*

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g ; \
		 s|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|dillorc|dillorc.sample|g' ${WRKSRC}/Makefile.in
	@${CP} ${WRKSRC}/dillorc ${WRKSRC}/dillorc.sample

pre-configure:
.if !defined(WITH_DILLO_SSL)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   Set WITH_DILLO_SSL=yes in your make environment or on the"
	@${ECHO_CMD} "   commandline to enable experimental SSL support."
.endif
.if !defined(WITHOUT_DILLO_IPV6) && !defined(WITHOUT_IPV6)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   Set WITHOUT_DILLO_IPV6=yes (or WITHOUT_IPV6=yes) in your make"
	@${ECHO_CMD} "   environment or on the commandline to disable IPv6 support."
.endif
	@${ECHO_CMD} ""

.include <bsd.port.mk>
