# New ports collection makefile for:	mime-support
# Date created:		7 March 2003
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	mime-support
PORTVERSION=	3.21.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/${PORTNAME:C/^(.).*$/\1/}/${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:C/(.*)\.([^.])/\1-\2/}

MAINTAINER=	corecode@corecode.ath.cx
COMMENT=	MIME Media Types list

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes

do-install:
	@${INSTALL_DATA} ${WRKSRC}/mime.types ${PREFIX}/etc

.include <bsd.port.mk>
