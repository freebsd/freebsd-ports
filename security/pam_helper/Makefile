# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pam_helper
PORTVERSION=	1.0
CATEGORIES=	security sysutils
MASTER_SITES=	http://www.marcuscom.com/pam_helper/

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Authenticate applications requiring PAM services

USES=		tar:bzip2 uidfix
MAKE_ARGS=	BINOWN=${UID}

PLIST_FILES=	bin/pam_helper

.include <bsd.port.mk>
