# New ports collection makefile for:	etlfonts-noncjk
# Date created:		3 Nov 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	etlfonts-noncjk
PORTVERSION= 	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.etl.go.jp/pub/mule/fonts/
DISTNAME=	non-cjk
EXTRACT_SUFX=	.tar

MAINTAINER=	mita@jp.FreeBSD.org

EXTRACT_CMD=		${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty
USE_X_PREFIX=	yes

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/*.gz

post-install:
	@${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

.include <bsd.port.mk>
