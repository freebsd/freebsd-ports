# New ports collection makefile for:	syslog-ng
# Date created:		10 november 1006
# Whom:			Ivan Lago <ivan.lago@ifom-ieo-campus.it>
#
# $FreeBSD$
#

PORTNAME=	syslog-ng
PORTVERSION=	3.0.3
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/files/syslog-ng/sources/$(PORTVERSION)/source/
PKGNAMESUFFIX=	3
DISTFILES=	$(PORTNAME)_$(PORTVERSION).tar.gz

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A powerful syslogd replacement

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet
LIB_DEPENDS=	evtlog.0:${PORTSDIR}/sysutils/eventlog

MAN5=		syslog-ng.conf.5
MAN8=		syslog-ng.8

USE_RC_SUBR=	syslog-ng.sh
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
SUB_FILES=	pkg-message
SUB_LIST=	RC_SUBR_SUFFIX=${RC_SUBR_SUFFIX}
USE_OPENSSL=	yes


LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc --localstatedir=/var/db \
		--enable-dynamic-linking --with-libnet=${LOCALBASE}/bin
CONFIGURE_ENV=	CFLAGS="`${LIBNET_CONFIG} --cflags` ${CFLAGS}" \
		LDFLAGS="`${LIBNET_CONFIG} --libs` ${LDFLAGS}" \
		OPENSSL_CFLAGS="${OPENSSL_CFLAGS}" \
		OPENSSL_LIBS="${OPENSSL_LDFLAGS} -lcrypto -lssl"


.if defined(WITH_TCP_WRAPPERS)
CONFIGURE_ARGS+=--enable-tcp-wrapper
.endif

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 700000
BROKEN=		Does not build under FreeBSD 6.4
.endif

post-patch:
	@${REINPLACE_CMD} -e 's:__PREFIX__:${PREFIX}:g' ${WRKSRC}/src/syslog-ng.h
	@${REINPLACE_CMD} -e 's:libnet-config:libnet11-config:g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} \
			${PREFIX}/share/doc/syslog-ng \
			${PREFIX}/share/doc/syslog-ng/sgml
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/syslog-ng
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/syslog-ng
.endif
	@if [ ! -f ${PREFIX}/etc/syslog-ng.conf.sample ]; then \
		${INSTALL_DATA} ${FILESDIR}/syslog-ng.conf.sample ${PREFIX}/etc; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
