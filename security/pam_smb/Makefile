# New ports collection makefile for:    pam_smb
# Date created:                         20 Jun 2001
# Whom:                                 nsayer
#
# $FreeBSD$

PORTNAME=	pam_smb
PORTVERSION=	1.1.6
CATEGORIES=	security
MASTER_SITES=   ftp://ftp.samba.org/pub/samba/%SUBDIR%/ \
		ftp://ring.asahi-net.or.jp/pub/net/samba/%SUBDIR%/ \
		ftp://samba.anu.edu.au/pub/samba/%SUBDIR%/ \
		ftp://de.samba.org/pub/mirror/samba/%SUBDIR%/ \
		ftp://se.samba.org/pub/samba/%SUBDIR%/ \
		ftp://ftp.sunet.se/pub/unix/utilities/samba/%SUBDIR%/
MASTER_SITE_SUBDIR=pam_smb

MAINTAINER=	nsayer@FreeBSD.org

USE_AUTOCONF=	yes
USE_GMAKE=	yes
MAKE_ENV+=	PREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

post-patch:
	${PERL} -pi -e s%CONFDIR%\"${PREFIX}/etc\"% ${WRKSRC}/pam_read_conf.c
	${PERL} -pi -e s%CONFDIR%\"${PREFIX}/etc\"% ${WRKSRC}/pam_smb_auth.c

do-install:
	${INSTALL_DATA} ${WRKSRC}/pam_smb_auth.so ${PREFIX}/lib
	${INSTALL_DATA} ${FILESDIR}/pam_smb.conf.sample ${PREFIX}/etc

post-install:
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
