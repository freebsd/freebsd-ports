# New ports collection makefile for:    pam_smb
# Date created:                         20 Jun 2001
# Whom:                                 nsayer
#
# $FreeBSD$

PORTNAME=	pam_smb
PORTVERSION=	1.9.9
CATEGORIES=	security
MASTER_SITES=   http://www.csn.ul.ie/~airlied/pam_smb/devel/

MAINTAINER=	nsayer@FreeBSD.org

USE_AUTOCONF_VER=213
USE_GMAKE=	yes
STARTUP_SCRIPT=	pam_smbd.sh.sample

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

post-patch:
	${PERL} -pi -e s,%%PREFIX%%,${PREFIX}, ${WRKSRC}/pamsmbd/pam_read_conf.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pamsmbd/pamsmbd ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/pamsmbm/pam_smb_auth.so ${PREFIX}/lib/
	${MKDIR} ${PREFIX}/share/doc/pam_smb/
	${INSTALL_DATA} ${WRKSRC}/BUGS ${PREFIX}/share/doc/pam_smb/
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/pam_smb/
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/pam_smb/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pam_smb/
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/pam_smb/
	${INSTALL_DATA} ${WRKSRC}/pam_smb.conf.example ${PREFIX}/etc/
	${INSTALL_DATA} ${WRKSRC}/pam_smb.conf.example2 ${PREFIX}/etc/
	${INSTALL_SCRIPT} ${FILESDIR}/${STARTUP_SCRIPT} ${PREFIX}/etc/rc.d/
	${PERL} -pi -e s,%%PREFIX%%,${PREFIX}, ${PREFIX}/etc/rc.d/${STARTUP_SCRIPT}

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.post.mk>
