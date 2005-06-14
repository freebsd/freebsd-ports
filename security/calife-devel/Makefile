# New ports collection makefile for:	calife-devel
# Date created:				14 Jun 2005
# Whom:					Thomas Quinot <thomas@cuivre.fr.eu.org>
#
# $FreeBSD$
#

PORTNAME=	calife
PORTVERSION=	3.0
CATEGORIES=	security
MASTER_SITES=	http://www.keltia.net/download/
DISTNAME=	calife-3.0pre4

MAINTAINER=	thomas@FreeBSD.org
COMMENT=	A lightweight alternative to sudo

USE_BZIP2=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pam --with-etcdir=${PREFIX}/etc

CONFLICTS?=	calife-2.*

MAN1=		calife.1
MAN5=		calife.auth.5

post-install:
	@${INSTALL_DATA} ${WRKSRC}/calife.pam ${PREFIX}/etc/pam.d/calife.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
