# New ports collection makefile for:	stunnel
# Date created:		Mon Jan 11 11:53:54 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	stunnel
PORTVERSION=	4.04
CATEGORIES=	security
MASTER_SITES=	http://www.stunnel.org/download/stunnel/src/ \
		ftp://stunnel.mirt.net/stunnel/ \
		ftp://opensores.thebunker.net/pub/mirrors/stunnel/ \
		ftp://ftp.cryptoarchive.net/pub/cryptoarchive/mirrors/opensores.thebunker.net/pub/mirrors/stunnel/

MAINTAINER=	roam@FreeBSD.org

USE_OPENSSL=	YES
USE_REINPLACE=	YES

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/tmp --with-pem-dir=${PEM_DIR} \
		--enable-static

MAN8=		stunnel.8 stunnel.pl.8

PEM_DIR?=	${PREFIX}/etc

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
	@${SED} "s+!!PREFIX!!+${PREFIX}+g" < ${FILESDIR}/stunnel.sh \
		> ${PREFIX}/etc/rc.d/stunnel.sh.sample
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/stunnel.sh.sample
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL
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
	@${ECHO} "The new certificate will be saved into ${PREFIX}/etc/stunnel.pem"
	@${ECHO} "**************************************************************************"
	@${ECHO} ""
	@(cd ${WRKSRC}/tools/; make stunnel.pem)
	${INSTALL} -m 600 ${WRKSRC}/tools/stunnel.pem ${PEM_DIR}/

.include <bsd.port.mk>
