# Created by: Damien Bobillot
# $FreeBSD$

PORTNAME=	pam_jail
PORTVERSION=	0.4
CATEGORIES=	security
MASTER_SITES=	http://www.triades.net/downloads/

MAINTAINER=	damien.bobillot_pam_jail@m4x.org
COMMENT=	PAM module dropping users in jails after login

LICENSE=	BSD3CLAUSE

SUB_FILES=	pkg-message
PLIST_FILES=	lib/pam_jail.so lib/pam_jail.so.1 man/man8/pam_jail.8.gz

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pam_jail.so.1 ${STAGEDIR}${PREFIX}/lib/
	${LN} -sf pam_jail.so.1 ${STAGEDIR}${PREFIX}/lib/pam_jail.so
	${INSTALL_MAN} ${WRKSRC}/pam_jail.8 ${STAGEDIR}${PREFIX}/man/man8/

.include <bsd.port.post.mk>
