# New ports collection makefile for:    pam_pwdfile
# Date created:				Aug 31, 2001
# Whom:	      				Michael Schout <mschout@gkg.net>
#
# $FreeBSD$
#

PORTNAME=	pam_pwdfile
PORTVERSION=	0.95
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cpbotha.net/pub/pam_pwdfile/

MAINTAINER=	mschout@gkg.net

MAKEFILE=	${FILESDIR}/Makefile.bsd

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${LOCALBASE}/${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/changelog \
		${WRKSRC}/INSTALL  ${LOCALBASE}/${DOCDIR}
DOCDIR=		share/doc/pam_pwdfile
PLIST_SUB+=	DOCDIR=${DOCDIR}
.endif

.include <bsd.port.mk>
