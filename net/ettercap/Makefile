# New ports collection makefile for:   ettercap
# Date created:        19 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ettercap
PORTVERSION=	0.6.b
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_PACKETSTORM:S:%SUBDIR%:sniffers/ettercap:}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A network sniffer/interceptor/injector/logger for switched LANs

USE_REINPLACE=	yes
.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
.endif
GNU_CONFIGURE=	yes
WANT_GNOME=	yes

MAN8=		ettercap.8

.include <bsd.port.pre.mk>

CFLAGS+=		${PTHREAD_CFLAGS}

CONFIGURE_TARGET=	-build=${ARCH}-portbld-freebsd${OSREL}
.if defined(WITHOUT_SSL)
CONFIGURE_ARGS=		--without-openssl
PLIST_SUB+=		SSL="@comment "
.else
CONFIGURE_ARGS=		--with-openssl=${OPENSSLBASE}
PLIST_SUB+=		SSL=""
.endif
.if ${HAVE_GNOME:Mgtk20}!=""
USE_GNOME+=		gtk20
PKGNAMESUFFIX=		-gnome
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif
CONFIGURE_ENV=		WGET_PATH=""

ALL_TARGET=		all plug-ins

INSTALL_TARGET=		install plug-ins_install
.if !defined(NOPORTDOCS)
INSTALL_TARGET+=	install-doc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${MV} -f ${WRKSRC}/share/lc-converter.c ${WRKSRC}

post-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/lc-converter ${WRKSRC}/lc-converter.c

post-install::
	${INSTALL_PROGRAM} ${WRKSRC}/lc-converter ${PREFIX}/bin

.include <bsd.port.post.mk>
