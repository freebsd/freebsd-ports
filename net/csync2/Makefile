# New ports collection makefile for:	net/csync2
# Date created:				16 May 2007
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	csync2
PORTVERSION=	1.34
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	http://oss.linbit.com/csync2/ \
		http://people.freebsd.org/~aaron/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cluster synchronization tool

LIB_DEPENDS=	rsync.1:${PORTSDIR}/net/librsync \
		tasn1.4:${PORTSDIR}/security/libtasn1 \
		gnutls.40:${PORTSDIR}/security/gnutls \
		sqlite.2:${PORTSDIR}/databases/sqlite2 \
		gcrypt.16:${PORTSDIR}/security/libgcrypt \
		gpg-error.0:${PORTSDIR}/security/libgpg-error

MAN1=	csync2.1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	etc/csync2.cfg-dist \
		sbin/csync2 \
		sbin/csync2-compare

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
