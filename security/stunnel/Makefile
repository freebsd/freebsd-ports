# New ports collection makefile for:	stunnel
# Date created:		Mon Jan 11 11:53:54 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	stunnel
PORTVERSION=	3.22
CATEGORIES=	security
MASTER_SITES=	http://www.stunnel.org/download/stunnel/src/ \
		ftp://stunnel.mirt.net/stunnel/ \
		ftp://opensores.thebunker.net/pub/mirrors/stunnel/ \
		ftp://ftp.cryptoarchive.net/pub/cryptoarchive/mirrors/opensores.thebunker.net/pub/mirrors/stunnel/

MAINTAINER=	martti.kuparinen@iki.fi

USE_OPENSSL=	YES
IS_INTERACTIVE=	YES	# prompts for information while generating certificate

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/run --with-pem-dir=${PEM_DIR}

MAN8=		stunnel.8

PEM_DIR?=	${PREFIX}/etc

post-install:
	@${SED} "s+!!PREFIX!!+${PREFIX}+g" < ${FILESDIR}/stunnel.sh \
		> ${PREFIX}/etc/rc.d/stunnel.sh.sample
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/stunnel.sh.sample
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
	@(cd ${WRKSRC}; make cert)
	${INSTALL} -m 600 ${WRKSRC}/stunnel.pem ${PEM_DIR}/

.include <bsd.port.mk>
