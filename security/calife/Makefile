# Created by: Thomas Quinot <thomas@cuivre.fr.eu.org>
# $FreeBSD$

PORTNAME=	calife
PORTVERSION=	3.0.1
CATEGORIES=	security
MASTER_SITES=	http://assets.keltia.net/calife/
DISTNAME=	calife-3.0.1
PKGNAMESUFFIX=	-devel

MAINTAINER=	thomas@FreeBSD.org
COMMENT=	Lightweight alternative to sudo

USE_BZIP2=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc

CONFIGURE_ARGS+=	--with-pam

CONFLICTS?=	calife-2.*

MAN1=		calife.1
MAN5=		calife.auth.5

NO_STAGE=	yes
post-install:
	@${INSTALL_DATA} ${WRKSRC}/pam/freebsd5 ${PREFIX}/etc/pam.d/calife.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
