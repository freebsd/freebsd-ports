# New ports collection makefile for:	balsa
# Date created:				02 December 1998
# Whom:					Glenn Johnson <gljohns@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	balsa
PORTVERSION=	1.2.3
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.theochem.kth.se/~pawsa/balsa/ \
		ftp://ftp.newton.cx/pub/balsa/

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	esmtp.5:${PORTSDIR}/mail/libesmtp \
		ldap.2:${PORTSDIR}/net/openldap2 \
		aspell.11:${PORTSDIR}/textproc/aspell \
		pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	${LOCALBASE}/bin/ispell:${PORTSDIR}/textproc/ispell

USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
USE_OPENSSL=	yes
LIBTOOLFILES=	libmutt/configure
CONFIGURE_ARGS=	--enable-threads \
		--enable-gtkhtml \
		--enable-ldap \
		--disable-more-warnings \
		--with-ssl
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgiconv"

MAN1=		balsa.1

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|-liconv|-lgiconv|g ; s|iconv_open|libiconv_open|g ; \
		 s|([^g])iconv.h|\1giconv.h|g' \
			${WRKSRC}/configure ${WRKSRC}/libmutt/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g ; \
		 s|\$\(gnomedatadir\)/gnome|\$\(gnomedatadir\)|g'

.include <bsd.port.mk>
