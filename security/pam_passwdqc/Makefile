# New ports collection makefile for:	pam_passwdqc
# Date created:				01/04/2002
# Whom:		Dominic Marks <dominic_marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	pam_passwdqc
PORTVERSION=	0.4
CATEGORIES=	security
MASTER_SITES=	http://www.openwall.com/passwdqc/

MAINTAINER=	dominic_marks@btinternet.com

do-install:
	@${INSTALL_DATA} ${WRKSRC}/pam_passwdqc.so ${PREFIX}/lib

.include <bsd.port.mk>
