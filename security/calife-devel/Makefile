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
DISTNAME=	calife-3.0pre5

MAINTAINER=	thomas@FreeBSD.org
COMMENT=	A lightweight alternative to sudo

LATEST_LINK=	${PORTNAME}-devel

USE_BZIP2=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-etcdir=${PREFIX}/etc

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
CONFIGURE_ARGS+=	--with-pam
.endif

CONFLICTS?=	calife-2.*

MAN1=		calife.1
MAN5=		calife.auth.5

post-install:
.if ${OSVERSION} >= 500000
	@${INSTALL_DATA} ${WRKSRC}/calife.pam ${PREFIX}/etc/pam.d/calife.sample
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
