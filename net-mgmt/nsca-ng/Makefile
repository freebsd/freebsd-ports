# Created by: Alexander Sulfrian <alexander@sulfrian.net>
# $FreeBSD: head/net-mgmt/nsca-ng/Makefile 390689 2015-06-27 01:59:02Z amdmi3 $

PORTNAME=	nsca-ng
PORTVERSION=	1.4
CATEGORIES=	net-mgmt
MASTER_SITES=	https://www.nsca-ng.org/download/ http://www.nsca-ng.org/download/

MAINTAINER=	alexander@sulfrian.net
COMMENT=	Nagios Service Check Acceptor

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libev.so:${PORTSDIR}/devel/libev

.if !defined(PKGNAMESUFFIX)
LIB_DEPENDS+=	libconfuse.so:${PORTSDIR}/devel/libconfuse
.endif

CONFLICTS?=	nsca-2.* nsca27-2.*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/spool/nagios --with-openssl=/usr/local
USE_OPENSSL=	yes

.if !defined(PKGNAMESUFFIX)
USE_RC_SUBR=	nsca-ng
CONFIGURE_ARGS+=	--enable-server
.endif

PORTDOCS=		NEWS COPYING README PROTOCOL TODO

.include <bsd.port.options.mk>

.if defined(OPENSSL_PORT) && \
	( ${OPENSSL_PORT} == security/libressl || ${OPENSSL_PORT} == security/libressl-devel )
CONFIGURE_ARGS+=	--with-openssl=/usr
CONFIGURE_ENV+=		SSLCPPARGS=-I/usr/include SSLLDFLAGS=-L/usr/lib
EXTRA_PATCHES=		${PATCHDIR}/extra-patch-LibreSSL
.else
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.endif

.if ${OSVERSION} < 1000000
WITH_OPENSSL_PORT=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

post-install:
.if defined(PKGNAMESUFFIX)
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios/
	${LN} -s ${PREFIX}/sbin/send_nsca ${STAGEDIR}${PREFIX}/libexec/nagios/send_nsca

	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/contrib && ${INSTALL_DATA} ${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

	cd ${STAGEDIR}${PREFIX}/etc && ${MV} send_nsca.cfg send_nsca.cfg.sample
	# remove files not used here
	cd ${STAGEDIR}${PREFIX} && ${RM} man/man8/nsca-ng.8 man/man5/nsca-ng.cfg.5
.else
	cd ${STAGEDIR}${PREFIX}/etc && ${MV} nsca-ng.cfg nsca-ng.cfg.sample
	# remove files not used here
	cd ${STAGEDIR}${PREFIX} && ${RM} etc/send_nsca.cfg man/man5/send_nsca.cfg.5 \
		man/man8/send_nsca.8 sbin/send_nsca
.endif

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
