# New ports collection makefile for:    atp
# Date created:         9 Nov 1997
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		atp
PORTVERSION=		1.50
PORTREVISION=	1
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/bbs/mail
DISTFILES=		${DISTNAME}-src.tar.gz

MAINTAINER=		ports@FreeBSD.org
COMMENT=	A QWK message packet reader and composer for FreeBSD

RUN_DEPENDS=		zip:${PORTSDIR}/archivers/zip \
			unzip:${PORTSDIR}/archivers/unzip

USE_GMAKE=		YES
GNU_CONFIGURE=		YES

MAN1=			atp.1 \
			atpdiag.1 \
			rot13.1
MAN3=			editline.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
