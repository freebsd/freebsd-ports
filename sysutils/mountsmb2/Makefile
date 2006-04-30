# New ports collection makefile for:	mountsmb2
# Date created:				17 Mar 2006
# Whom:					Rashid N. Achilov <shelton@granch.ru>
#
# $FreeBSD$
#

PORTNAME=	mountsmb2
PORTVERSION=	0.90.1
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://ftp.granch.ru/pub/other/

MAINTAINER=	shelton@www.granch.ru
COMMENT=	SMB/CIFS shares mounting scripts to do it at login

RUN_DEPENDS=	findsmb:${PORTSDIR}/net/samba3 \
		sudo:${PORTSDIR}/security/sudo \
		gawk:${PORTSDIR}/lang/gawk

USE_BZIP2=	yes
NO_BUILD=	yes

do-install:

.for i in smb2awk smb2nsmbrc mountsmb2
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	-@${MKDIR} ${EXAMPLESDIR}

.for i in sudoers .login .nsmbrc .mssmbrc
	${INSTALL_DATA} ${WRKSRC}/${i} ${EXAMPLESDIR}
.endfor

	-@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.FreeBSD ${DOCSDIR}

	@${SED} -e "s,%%EXAMPLESDIR%%,${EXAMPLESDIR},g" ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
