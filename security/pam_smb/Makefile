# Created by: nsayer
# $FreeBSD$

PORTNAME=	pam_smb
PORTVERSION=	2.0.0.r6
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SAMBA} \
		http://www.csn.ul.ie/~airlied/pam_smb/v2/
MASTER_SITE_SUBDIR=	samba/pam_smb/v2
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NetBIOS domain logon PAM module

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
USES=		perl5
USE_LDCONFIG=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
STARTUP_SCRIPT=	pam_smbd.sh.sample

WRKSRC=		${WRKDIR}/${DISTNAME}

NO_STAGE=	yes
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
