# New ports collection makefile for:	clamav-devel
# Date created:				13 June 2003
# Whom:					Rob Evers <rob@debank.tv>
#
# $FreeBSD$
#

PORTNAME=	clamav
PORTVERSION=	20030926
CATEGORIES=	security
MASTER_SITES=	http://clamav.sourceforge.net/snapshot/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	rob@debank.tv
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
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--disable-clamav --enable-bigstack
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

MAN1=		clamscan.1 freshclam.1 sigtool.1 clamdscan.1 clamav-milter.1
MAN5=		clamav.conf.5
MAN8=		clamd.8

CLAMAVUSER?=	clamav
SPOOLDIR?=	/var/clamd
PLIST_SUB+=	SPOOLDIR="${SPOOLDIR}"
PLIST_SUB+=	CLAMAVUSER="${CLAMAVUSER}"

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

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=" ${FILESDIR}/clamav-milter.sh \
		> ${WRKSRC}/clamav-milter.sh
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=" ${FILESDIR}/clamav-clamd.sh \
		> ${WRKSRC}/clamav-clamd.sh

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/lib/sendmail|/usr/sbin/sendmail|g' \
		${WRKSRC}/clamav-milter/clamav-milter.c

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PREFIX}
	${INSTALL_SCRIPT} ${WRKSRC}/clamav-clamd.sh \
		${LOCALBASE}/etc/rc.d/clamav-clamd.sh.sample
.if defined(WITH_MILTER)
	${INSTALL_SCRIPT} ${WRKSRC}/clamav-milter.sh \
		${LOCALBASE}/etc/rc.d/clamav-milter.sh.sample
.endif

.include <bsd.port.post.mk>
