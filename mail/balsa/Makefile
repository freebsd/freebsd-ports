# New ports collection makefile for:	balsa
# Date created:				02 December 1998
# Whom:					Glenn Johnson <gljohns@bellsouth.net>
#
# $FreeBSD$
#

PORTNAME=	balsa
PORTVERSION=	1.4.4
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	http://balsa.gnome.org/ \
		http://www.theochem.kth.se/~pawsa/balsa/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A mail reader for the GNOME desktop

LIB_DEPENDS=	ldap.2:${PORTSDIR}/net/openldap20-client \
		aspell.15:${PORTSDIR}/textproc/aspell \
		pcre.0:${PORTSDIR}/devel/pcre \
		esmtp.6:${PORTSDIR}/mail/libesmtp
RUN_DEPENDS=	${LOCALBASE}/bin/ispell:${PORTSDIR}/textproc/ispell

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomeprint gnomevfs gtkhtml gnometarget
USE_LIBTOOL=	yes
USE_OPENSSL=	yes
LIBTOOLFILES=	configure libmutt/configure
CONFIGURE_ARGS=	--enable-threads \
		--enable-gtkhtml \
		--enable-ldap \
		--disable-more-warnings \
		--with-ssl
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -liconv"

MAN1=		balsa.1

CONFLICTS=	balsa2-*

.include <bsd.port.mk>
