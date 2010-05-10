# New ports collection makefile for:    pam_jail
# Date created:                         28 March 2010
# Whom:                                 Damien Bobillot
#
# $FreeBSD$
#

PORTNAME=	pam_jail
PORTVERSION=	0.3
CATEGORIES=	security
MASTER_SITES=	http://www.triades.net/downloads/

MAINTAINER=	damien.bobillot_pam_jail@m4x.org
COMMENT=	A PAM module dropping users in jails after login

MAN8=		pam_jail.8
MANCOMPRESSED=	yes
SUB_FILES=	pkg-message
PLIST_FILES=	lib/pam_jail.so lib/pam_jail.so.1

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pam_jail.so.1 ${PREFIX}/lib/
	${LN} -sf pam_jail.so.1 ${PREFIX}/lib/pam_jail.so
	${INSTALL_MAN} ${WRKSRC}/pam_jail.8.gz ${PREFIX}/man/man8/

post-install:
	@${CAT} ${PKGMESSAGE}

.if ${OSVERSION} < 700000
BROKEN=		jail version not supported
.endif

.include <bsd.port.post.mk>
