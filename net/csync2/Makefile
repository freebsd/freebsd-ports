# New ports collection makefile for:	net/csync2
# Date created:				16 May 2007
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	csync2
PORTVERSION=	1.34
PORTREVISION=	8
CATEGORIES=	net
MASTER_SITES=	http://oss.linbit.com/csync2/ \
		http://people.freebsd.org/~aaron/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	A cluster synchronization tool

LIB_DEPENDS=	rsync.1:${PORTSDIR}/net/librsync \
		tasn1.4:${PORTSDIR}/security/libtasn1 \
		gnutls.40:${PORTSDIR}/security/gnutls \
		sqlite.2:${PORTSDIR}/databases/sqlite2 \
		gcrypt.16:${PORTSDIR}/security/libgcrypt \
		gpg-error.0:${PORTSDIR}/security/libgpg-error

OPTIONS=	CSYNC2_COMPARE "Install csync2-compare script" off

.include <bsd.port.pre.mk>

MAN1=		csync2.1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBGNUTLS_CONFIG="${LOCALBASE}/bin/pkg-config gnutls"

USE_RC_SUBR=	csync2

PLIST_FILES=	etc/csync2.cfg-dist \
		sbin/csync2

.if defined(WITH_CSYNC2_COMPARE)
RUN_DEPENDS+=	bash>=0:${PORTSDIR}/shells/bash
PLIST_FILES+=	sbin/csync2-compare
CSYNC2_COMPARE=	csync2-compare
.else
CSYNC2_COMPARE=
.endif

SUB_FILES=	pkg-install

post-patch:
	${REINPLACE_CMD} -E "s#%%CSYNC2_COMPARE%%#${CSYNC2_COMPARE}#" ${WRKSRC}/Makefile.in

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
