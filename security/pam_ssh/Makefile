# New ports collection makefile for:	pam_ssh
# Date created:				12 April 2001
# Whom:					ajk@iu.edu
#
# $FreeBSD$
#

PORTNAME=	pam_ssh
PORTVERSION=	1.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pam-ssh

MAINTAINER=	ajk@iu.edu

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pam_ssh.so ${PREFIX}/lib

.include <bsd.port.mk>
