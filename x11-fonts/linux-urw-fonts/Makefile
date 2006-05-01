# New ports collection makefile for:	linux-urw-fonts
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		urw-fonts
PORTVERSION=		2.3
CATEGORIES=		x11-fonts linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-1
EXTRACT_SUFX=	.noarch.rpm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Truetype fonts for use with Linux programs

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
MD5_FILE=	${MASTERDIR}/distinfo

pre-install:
	@cd ${MASTERDIR}/files; \
	cp fonts.* ${WRKSRC}/usr/share/fonts/default/Type1

.include <bsd.port.mk>
