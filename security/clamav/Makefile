# New ports collection makefile for:	clamav
# Date created:		15 July 2002
# Whom:			markun@onohara.to
#
# $FreeBSD$
#

PORTNAME=	clamav
PORTVERSION=	0.60
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	clamav

MAINTAINER=	markun@onohara.to
COMMENT=	Command line virus scanner written entirely in C

RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		unarj:${PORTSDIR}/archivers/unarj \
		unrar:${PORTSDIR}/archivers/unrar \
		zoo:${PORTSDIR}/archivers/zoo \
		arc:${PORTSDIR}/archivers/arc \
		unzip:${PORTSDIR}/archivers/unzip

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--disable-clamav --enable-bigstack
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
MAN1=		clamscan.1 freshclam.1 sigtool.1 clamdscan.1 clamav-milter.1
MAN5=		clamav.conf.5
MAN8=		clamd.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 510001
# compiles only with optimizer
CFLAGS+=	-O
LDFLAGS+=	-lcipher
.endif

.if defined(WITH_MILTER)
CONFIGURE_ARGS+=	--enable-milter
PLIST_SUB+=	CLAMAV-MILTER:=""
.else
PLIST_SUB+=	CLAMAV-MILTER:="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

pre-install:
	@${ECHO} "===>   Creating custom user to run clamav..."
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${ECHO} "===>   Setting permissions..."
	@${SETENV} PKG_PREFIX=${PREFIX} ${sh} \
	${SH} ${PKGINSTALL} ${PREFIX} POST-INSTALL

.include <bsd.port.post.mk>
