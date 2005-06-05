# New ports collection makefile for:	stunnel
# Date created:		Mon Jan 11 11:53:54 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	stunnel
PORTVERSION=	4.10
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.stunnel.org/download/stunnel/src/ \
		ftp://stunnel.mirt.net/stunnel/OBSOLETE/ \
		ftp://opensores.thebunker.net/pub/mirrors/stunnel/download/stunnel/src/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	SSL encryption wrapper for standard network daemons

USE_OPENSSL=	YES
USE_REINPLACE=	YES
USE_LIBTOOL_VER=	15
USE_RC_SUBR=	YES

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--localstatedir=/var/tmp --with-pem-dir=${PEM_DIR} \
		--enable-static

.if !defined(NOPORTDOCS)
MAN8=		stunnel.8 stunnel.fr.8 stunnel.pl.8
.endif

PEM_DIR?=	${PREFIX}/etc

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-patch:
# place files under /var/tmp so that this can be run by an unprivileged user
# user stunnel and group stunnel
	@${REINPLACE_CMD} -E -e 's|\@prefix\@/var/run/stunnel/|/var/tmp/stunnel|; \
		s|nobody|stunnel|;s|nogroup|stunnel|' \
		${WRKSRC}/tools/stunnel.conf-sample.in
	@${REINPLACE_CMD} -E -e 's|localstatedir/run/stunnel.pid|localstatedir/stunnel.pid|' \
		${WRKSRC}/configure.ac ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -type f -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E -e 's,@(ACLOCAL|AUTO(MAKE|CONF|HEADER))@,/usr/bin/true,'
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e 's/ install-docDATA/ /; s/^(SUBDIRS.+)doc/\1/' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${SED} "s+!!PREFIX!!+${PREFIX}+g; s+!!RC_SUBR!!+${RC_SUBR}+g" \
		< ${FILESDIR}/stunnel.sh > ${WRKDIR}/stunnel.sh
	${INSTALL_SCRIPT} ${WRKDIR}/stunnel.sh ${PREFIX}/etc/rc.d/
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO} ""
	@${ECHO} "**************************************************************************"
	@${ECHO} "To create and install a new certificate, type \"make cert\""
	@${ECHO} ""
	@${ECHO} "And don't forget to check out the FAQ at http://www.stunnel.org/"
	@${ECHO} "**************************************************************************"
	@${ECHO} ""
	@${ECHO} "*********************** WARNING! WARNING! WARNING! ***********************"
	@${ECHO} "The stunnel startup script has been converted to rc_subr"
	@${ECHO} "format now.  You have to set at least the stunnel_enable"
	@${ECHO} "variable, and maybe also stunnel_config and stunnel_pidfile,"
	@${ECHO} "if you want stunnel to be started automatically at boot time!"
	@${ECHO} "**************************************************************************"
	@${ECHO} ""

cert:
	@${ECHO} ""
	@${ECHO} "**************************************************************************"
	@${ECHO} "The new certificate will be saved into ${PREFIX}/etc/stunnel.pem"
	@${ECHO} "**************************************************************************"
	@${ECHO} ""
	@(cd ${WRKSRC}/tools/; make stunnel.pem)
	${INSTALL} -m 600 ${WRKSRC}/tools/stunnel.pem ${PEM_DIR}/

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
.if !defined(WITH_STUNNEL_SSL_ENGINE)
EXTRA_PATCHES=	${FILESDIR}/ssl-noengine.patch
pre-patch:
	@${ECHO} "*************************************************************************"
	@${ECHO} "Note: you have to explicitly define WITH_STUNNEL_SSL_ENGINE to activate"
	@${ECHO} "the OpenSSL ENGINE code on FreeBSD 5.x or 6.x."
	@${ECHO} "There are known reliability issues with stunnel and the OpenSSL ENGINE"
	@${ECHO} "code, so you are advised not to enable it."
	@${ECHO} "*************************************************************************"
.else
pre-patch:
	@${ECHO} "*************************************************************************"
	@${ECHO} "Note: you have defined WITH_STUNNEL_SSL_ENGINE.  Now stunnel will activate"
	@${ECHO} "the OpenSSL ENGINE code even on FreeBSD 5.x."
	@${ECHO} "There are known reliability issues with stunnel and the OpenSSL ENGINE"
	@${ECHO} "code.  You have enabled it at your own risk."
	@${ECHO} "*************************************************************************"
.endif
.endif

.include <bsd.port.post.mk>
