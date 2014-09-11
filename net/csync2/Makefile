# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	csync2
PORTVERSION=	1.34
PORTREVISION=	19
CATEGORIES=	net
MASTER_SITES=	http://oss.linbit.com/csync2/ \
		http://people.freebsd.org/~aaron/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Cluster synchronization tool

LIB_DEPENDS=	librsync.so:${PORTSDIR}/net/librsync \
		libtasn1.so:${PORTSDIR}/security/libtasn1 \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libsqlite.so:${PORTSDIR}/databases/sqlite2 \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error

OPTIONS_DEFINE=	CSYNC2_COMPARE
CSYNC2_COMPARE_DESC=	Install csync2-compare script

USES=		pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc
CONFIGURE_ENV=	LIBGNUTLS_CONFIG="${LOCALBASE}/bin/pkg-config gnutls"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_RC_SUBR=	csync2

PLIST_FILES=	etc/csync2.cfg-dist \
		sbin/csync2 \
		man/man1/csync2.1.gz

SUB_FILES=	pkg-install

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCSYNC2_COMPARE}
RUN_DEPENDS+=	bash>=0:${PORTSDIR}/shells/bash
PLIST_FILES+=	sbin/csync2-compare
CSYNC2_COMPARE=	csync2-compare
.else
CSYNC2_COMPARE=
.endif

post-patch:
	${REINPLACE_CMD} -E "s#%%CSYNC2_COMPARE%%#${CSYNC2_COMPARE}#" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
