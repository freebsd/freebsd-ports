# New ports collection makefile for:    pam_pwdfile
# Date created:				Aug 31, 2001
# Whom:	      				Michael Schout <mschout@gkg.net>
#
# $FreeBSD$
#

PORTNAME=	pam_pwdfile
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://cpbotha.net/files/pam_pwdfile/

MAINTAINER=	mschout@gkg.net
COMMENT=	A pam module for authenticating with flat passwd files

MAKEFILE=	${FILESDIR}/Makefile.bsd

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/changelog \
		${WRKSRC}/INSTALL  ${DOCSDIR}
.endif

.include <bsd.port.mk>
