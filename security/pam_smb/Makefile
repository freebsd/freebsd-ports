# New ports collection makefile for:    pam_smb
# Date created:                         20 Jun 2001
# Whom:                                 nsayer
#
# $FreeBSD$

PORTNAME=	pam_smb
PORTVERSION=	2.0.0.r5
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://pamsmb.sourceforge.net/v2/ \
		http://www.csn.ul.ie/~airlied/pam_smb/v2/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NetBIOS domain logon PAM module

INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
STARTUP_SCRIPT=	pam_smbd.sh.sample

WRKSRC=		${WRKDIR}/${DISTNAME}

post-patch:
	@${REINPLACE_CMD} -e s,%%PREFIX%%,${PREFIX}, ${WRKSRC}/pamsmbd/pam_read_conf.c
	@${REINPLACE_CMD} -e "s,-fPIC,-fPIC -DPIC," \
		${WRKSRC}/configure ${WRKSRC}/configure.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pamsmbd/pamsmbd ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/pamsmbm/pam_smb_auth.so ${PREFIX}/lib/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/BUGS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/pam_smb.conf.example ${PREFIX}/etc/
	${INSTALL_DATA} ${WRKSRC}/pam_smb.conf.example2 ${PREFIX}/etc/
	${INSTALL_SCRIPT} ${FILESDIR}/${STARTUP_SCRIPT} ${PREFIX}/etc/rc.d/
	${REINPLACE_CMD} -e s,%%PREFIX%%,${PREFIX}, ${PREFIX}/etc/rc.d/${STARTUP_SCRIPT}
	${RM} ${PREFIX}/etc/rc.d/${STARTUP_SCRIPT}.bak

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
