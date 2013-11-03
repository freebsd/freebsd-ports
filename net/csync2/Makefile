# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	csync2
PORTVERSION=	1.34
PORTREVISION=	15
CATEGORIES=	net
MASTER_SITES=	http://oss.linbit.com/csync2/ \
		http://people.freebsd.org/~aaron/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Cluster synchronization tool

LIB_DEPENDS=	rsync.1:${PORTSDIR}/net/librsync \
		tasn1.7:${PORTSDIR}/security/libtasn1 \
		gnutls.26:${PORTSDIR}/security/gnutls \
		sqlite.2:${PORTSDIR}/databases/sqlite2 \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		gpg-error.0:${PORTSDIR}/security/libgpg-error

OPTIONS_DEFINE=	CSYNC2_COMPARE
CSYNC2_COMPARE_DESC=	Install csync2-compare script

USES=	pkgconfig

NO_STAGE=	yes
.include <bsd.port.options.mk>

MAN1=		csync2.1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc
CONFIGURE_ENV=	LIBGNUTLS_CONFIG="${LOCALBASE}/bin/pkg-config gnutls"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_RC_SUBR=	csync2

PLIST_FILES=	etc/csync2.cfg-dist \
		sbin/csync2

.if ${PORT_OPTIONS:MCSYNC2_COMPARE}
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

.include <bsd.port.mk>
