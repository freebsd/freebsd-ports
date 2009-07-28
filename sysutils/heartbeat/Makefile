# New ports collection makefile for:	heartbeat
# Date created:				18 March 2005
# Whom:					Scott Kleihege <scott-ports@tummy.com>
#
# $FreeBSD$
#

PORTNAME=	heartbeat
PORTVERSION=	1.2.5
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://linux-ha.org/download/

MAINTAINER=	scott-ports@tummy.com
COMMENT=	Subsystem for High-Availability Clustering

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet
LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	glib12
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--disable-fatal-warnings \
			--with-initdir=${PREFIX}/etc/rc.d \
			--localstatedir=/var \
			--with-group-id=275 --with-ccmuser-id=275
CONFIGURE_ENV=	CPPFLAGS="`${LIBNET_CONFIG} --cflags`" \
		LDFLAGS="`${LIBNET_CONFIG} --libs`"

SUB_FILES=	pkg-install
PKGDEINSTALL=	${PKGINSTALL}

MAN1=		cl_status.1 hb_standby.1 hb_takeover.1
MAN8=		apphbd.8 heartbeat.8 ldirectord.8 meatclient.8 \
		stonith.8 supervise-ldirectord-config.8

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

post-patch:
	@${REINPLACE_CMD} -e "s|logrotate\.d||" \
		${WRKSRC}/heartbeat/Makefile.in \
		${WRKSRC}/ldirectord/Makefile.in

	@${REINPLACE_CMD} -e \
		's|libnet-config|${LIBNET_CONFIG}|; \
		 s|-lnet|`${LIBNET_CONFIG} --libs`|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|^\(docdir.*doc/\).*|\1${PORTNAME}|' \
		${WRKSRC}/configure.in \
		${WRKSRC}/configure \
		${WRKSRC}/doc/Makefile.am \
		${WRKSRC}/doc/Makefile.in
.else
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS.*\)doc\(.*\)|\1 \2|' \
		${WRKSRC}/Makefile.am \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/telecom/cms/Makefile.am \
		${WRKSRC}/telecom/cms/Makefile.in
.endif

.if !defined(BATCH)
BATCH=no
.endif

post-deinstall:
	@BATCH=${BATCH} ${SH} ${PKGINSTALL} ${PKGNAME} DEINSTALL

pre-install:
	@BATCH=${BATCH} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

# some subdirs treat man as documentation, therefor we have to install
# those man pages manually if NOPORTDOCS is defined

.if defined(NOPORTDOCS)
.for f in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${f} ${MANPREFIX}/man/man1
.endfor
.for f in apphbd.8 heartbeat.8
	${INSTALL_MAN} ${WRKSRC}/doc/${f} ${MANPREFIX}/man/man8
.endfor
.endif

.include <bsd.port.mk>
