# New ports collection makefile for:	etlfonts-noncjk
# Version required:	1.0
# Date created:		3 Nov 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.5 1998/08/07 22:43:08 asami Exp $
#

DISTNAME=	non-cjk
PKGNAME=	etlfonts-noncjk-1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.etl.go.jp/pub/mule/fonts/
EXTRACT_SUFX=	.tar

MAINTAINER=	mita@jp.FreeBSD.org

EXTRACT_CMD=		${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty
USE_X_PREFIX=	yes

post-extract:
	@gunzip ${WRKSRC}/*.gz

post-install:
	@${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

.include <bsd.port.mk>
