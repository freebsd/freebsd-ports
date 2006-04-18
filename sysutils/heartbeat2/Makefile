# New ports collection makefile for:	hearbeat
# Date created:				18 March 2005
# Whom:					Scott Kleihege <scott-ports@tummy.com>
#
# $FreeBSD$
#

PORTNAME=	heartbeat
PORTVERSION=	1.2.4
CATEGORIES=	sysutils
MASTER_SITES=	http://linux-ha.org/download/

MAINTAINER=	scott-ports@tummy.com
COMMENT=	Subsystem for High-Availability Clustering

BUILD_DEPENDS=	libnet*>=1.1.2,1:${PORTSDIR}/net/libnet
LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl \
		xml2.5:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	glib12
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS+=	--disable-fatal-warnings \
			--with-initdir=${PREFIX}/etc/rc.d

SUB_FILES=	pkg-install
PKGDEINSTALL=	${PKGINSTALL}

MAN1=		cl_status.1 hb_standby.1 hb_takeover.1
MAN8=		apphbd.8 heartbeat.8 ldirectord.8 meatclient.8 \
		stonith.8 supervise-ldirectord-config.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-lib-clplumbing-resource.h
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|logrotate\.d||" \
		${WRKSRC}/heartbeat/Makefile.in \
		${WRKSRC}/ldirectord/Makefile.in

.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|<sys/\(resource.h\)>|"\1"|' \
		${WRKSRC}/lib/clplumbing/coredumps.c
.endif

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

post-deinstall:
	@${SH} ${PKGINSTALL} ${PKGNAME} DEINSTALL

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

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

.include <bsd.port.post.mk>
