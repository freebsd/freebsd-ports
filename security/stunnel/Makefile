# New ports collection makefile for:	stunnel
# Date created:		Mon Jan 11 11:53:54 EET 1999
# Whom:			Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	stunnel
PORTVERSION=	3.8
CATEGORIES=	security
MASTER_SITES=	ftp://opensores.thebunker.net/pub/mirrors/stunnel/ \
		http://mike.daewoo.com.pl/computer/stunnel/ \
		ftp://ftp.cryptoarchive.net/pub/cryptoarchive/mirrors/opensores.thebunker.net/pub/mirrors/stunnel/

MAINTAINER=	martti.kuparinen@ericsson.com

USE_OPENSSL=	RSA

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/run

MAN8=		stunnel.8

cert:
	@(cd ${WRKSRC}; make cert)

post-build:
	@${ECHO} ""
	@${ECHO} "********************************************************************"
	@${ECHO} "To create and install a real certificate, execute \"make cert\" before"
	@${ECHO} "\"make install\"."
	@${ECHO} ""
	@${ECHO} "You can also create a real certificate later by executing"
	@${ECHO} "      # make cert"
	@${ECHO} "      # cp work/stunnel/stunnel.pem ${PREFIX}/certs/"
	@${ECHO} "********************************************************************"
	@${ECHO} ""

post-install:
	@${ECHO} ""
	@${ECHO} "**************************************************************************"
	@${ECHO} "Please check out the FAQ at http://www.onsight.com/faq/stunnel/"
	@${ECHO} "**************************************************************************"
	@${ECHO} ""

.include <bsd.port.mk>
