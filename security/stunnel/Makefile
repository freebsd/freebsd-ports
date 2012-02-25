# New ports collection makefile for:	stunnel
# Date created:		Mon Jan 11 11:53:54 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	stunnel
PORTVERSION=	4.52
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.stunnel.org/stunnel/%SUBDIR%/ \
		http://mirrors.zerg.biz/stunnel/%SUBDIR%/ \
		ftp://stunnel.mirt.net/stunnel/%SUBDIR%/ \
		ftp://ftp.nluug.nl/pub/networking/stunnel/%SUBDIR%/ \
		http://ftp.nluug.nl/pub/networking/stunnel/%SUBDIR%/ \
		ftp://ftp.surfnet.nl/pub/networking/stunnel/%SUBDIR%/ \
		http://ftp.surfnet.nl/pub/networking/stunnel/%SUBDIR%/ \
		http://mirrors.zerg.biz/stunnel/%SUBDIR%/
MASTER_SITE_SUBDIR=	. obsolete/4.x

MAINTAINER=	zi@FreeBSD.org
COMMENT=	SSL encryption wrapper for standard network daemons

# FIXME: IMHO, there really ought to be a GPL-2+ option or some such.
LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_AUTOTOOLS=	libtool
USE_RC_SUBR=	stunnel
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/tmp \
		--enable-static --disable-fips

.if !defined(NOPORTDOCS)
MAN8=		stunnel.8 stunnel.fr.8 stunnel.pl.8
.endif

OPTIONS=	FORK	"Ese the fork(3) threading model" off \
		PTHREAD	"Ese the pthread(3) threading model (default)" on \
		UCONTEXT	"Ese the ucontext(3) threading model" off \
		IPV6	"Enable IPv6 support" off \
		LIBWRAP	"Use TCP wrappers" on \
		SSL_PORT	"Use OpenSSL from the Ports Collection" off

.include <bsd.port.options.mk>

STUNNEL_USER?=	stunnel
STUNNEL_GROUP?=	stunnel

USERS=		${STUNNEL_USER}
GROUPS=		${STUNNEL_GROUP}

.if defined(WITH_SSL_PORT)
USE_OPENSSL=	YES
WITH_OPENSSL_PORT=	yes
CONFIGURE_ARGS+=	--with-ssl="${OPENSSLBASE}"
.else
CONFIGURE_ARGS+=	--with-ssl=/usr
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_LIBWRAP)
CONFIGURE_ARGS+=	--enable-libwrap
LDFLAGS+=		-lwrap
.else
CONFIGURE_ARGS+=	--disable-libwrap
.endif

.if defined(WITH_UCONTEXT) && defined(WITH_FORK) || defined(WITH_UCONTEXT) && defined(WITH_PTHREAD) || defined(WITH_FORK) && defined(WITH_PTHREAD)
BROKEN=	'The WITH_UCONTEXT, WITH_FORK and WITH_PTHREAD options are mutually exclusive - please specify at most one of them, the default is WITH_PTHREAD'
.endif

.if defined(WITH_UCONTEXT)
CONFIGURE_ARGS+=--with-threads=ucontext
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
.elif defined(WITH_FORK)
CONFIGURE_ARGS+=--with-threads=fork
.else
CONFIGURE_ARGS+=--with-threads=pthread
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
.endif

post-patch:
# place files under /var/tmp so that this can be run by an unprivileged
# user stunnel and group stunnel
	@${REINPLACE_CMD} -E -e 's|\@prefix\@/var/lib/stunnel/|/var/tmp/stunnel|; \
		s|nobody|stunnel|;s|nogroup|stunnel|' \
		${WRKSRC}/tools/stunnel.conf-sample.in
	${REINPLACE_CMD} -E -e 's|\$$\(prefix\)/var/run/stunnel/stunnel.pid|$$(localstatedir)/stunnel.pid|' \
		${WRKSRC}/src/Makefile.in
	@${FIND} ${WRKSRC} -type f -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E -e 's,@(ACLOCAL|AUTO(MAKE|CONF|HEADER))@,/usr/bin/true,'
	@${REINPLACE_CMD} -E -e 's|install-confDATA install-data-local|install-confDATA|g' \
		${WRKSRC}/tools/Makefile.in
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e 's/ install-docDATA/ /; s/^(SUBDIRS.+)doc/\1/' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E -e 's/([^n])install-examplesDATA/\1/' \
		${WRKSRC}/tools/Makefile.in
.endif

post-install:
	@${ECHO} ""
	@${ECHO} "**************************************************************************"
	@${ECHO} "To create and install a new certificate, type \"make cert\""
	@${ECHO} ""
	@${ECHO} "And don't forget to check out the FAQ at http://www.stunnel.org/"
	@${ECHO} "**************************************************************************"
	@${ECHO} ""

cert:
	@${ECHO} ""
	@${ECHO} "**************************************************************************"
	@${ECHO} "The new certificate will be saved into ${ETCDIR}/stunnel.pem"
	@${ECHO} "**************************************************************************"
	@${ECHO} ""
	@(cd ${WRKSRC}/tools/; make install-data-local)

.include <bsd.port.post.mk>
