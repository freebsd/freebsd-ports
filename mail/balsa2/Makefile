# New ports collection makefile for:	balsa2
# Date created:				19 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	balsa2
PORTVERSION=	2.0.2
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.theochem.kth.se/~pawsa/balsa/ \
		ftp://ftp.newton.cx/pub/balsa/
DISTNAME=	balsa-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/ispell:${PORTSDIR}/textproc/ispell
LIB_DEPENDS=	ldap.2:${PORTSDIR}/net/openldap2 \
		aspell.15:${PORTSDIR}/textproc/aspell \
		pcre.0:${PORTSDIR}/devel/pcre \
		esmtp.6:${PORTSDIR}/mail/libesmtp \
		gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui \
		gnomeprintui-2.0:${PORTSDIR}/x11-toolkits/libgnomeprintui \
		gtkhtml-2.0:${PORTSDIR}/www/libgtkhtml \
		gdbm.2:${PORTSDIR}/databases/gdbm
RUN_DEPENDS=	${LOCALBASE}/bin/ispell:${PORTSDIR}/textproc/ispell

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
USE_OPENSSL=	yes
LIBTOOLFILES=	libmutt/configure
CONFIGURE_ARGS=	--enable-threads \
		--enable-gtkhtml \
		--enable-ldap \
		--disable-more-warnings \
		--with-ssl \
		--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -liconv"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=		balsa.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' \
			${WRKSRC}/configure ${WRKSRC}/libmutt/configure
	@${FIND} ${WRKSRC} -name "Makefile.in*" | xargs ${REINPLACE_CMD} -e \
		's|[(]datadir[)]/gnome/|(datadir)/|g ; \
		 s|[(]datadir[)]/locale|(prefix)/share/locale|g ; \
		 s|[(]gnomedatadir[)]/gnome|(gnomedatadir)|g'

.include <bsd.port.mk>
