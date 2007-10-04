# New ports collection makefile for:	calife-devel
# Date created:				14 Jun 2005
# Whom:					Thomas Quinot <thomas@cuivre.fr.eu.org>
#
# $FreeBSD$
#

PORTNAME=	calife
PORTVERSION=	3.0
CATEGORIES=	security
MASTER_SITES=	ftp://frmug.org/pub/calife/ \
		http://www.keltia.net/download/
DISTNAME=	calife-3.0pre6

MAINTAINER=	thomas@FreeBSD.org
COMMENT=	A lightweight alternative to sudo

LATEST_LINK=	${PORTNAME}-devel

USE_BZIP2=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc

CONFIGURE_ARGS+=	--with-pam

CONFLICTS?=	calife-2.*

MAN1=		calife.1
MAN5=		calife.auth.5

post-install:
	@${INSTALL_DATA} ${WRKSRC}/pam/freebsd5 ${PREFIX}/etc/pam.d/calife.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
