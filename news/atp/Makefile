# New ports collection makefile for:    atp
# Version required:     1.50
# Date created:         9 Nov 1997
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=		atp-1.50-src
PKGNAME=		atp-1.50
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/bbs/mail

MAINTAINER=		dburr@FreeBSD.org

RUN_DEPENDS=		zip:${PORTSDIR}/archivers/zip \
			unzip:${PORTSDIR}/archivers/unzip

WRKSRC=                 ${WRKDIR}/${PKGNAME}

USE_GMAKE=		YES
GNU_CONFIGURE=		YES

MAN1=			atp.1 \
			atpdiag.1 \
			rot13.1
MAN3=			editline.3

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
