# New ports collection makefile for:	mountsmb2
# Date created:				17 Mar 2006
# Whom:					Rashid N. Achilov <shelton@granch.ru>
#
# $FreeBSD$
#

PORTNAME=	mountsmb2
PORTVERSION=	0.90.2
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://ftp.granch.ru/pub/other/

MAINTAINER=	shelton@www.granch.ru
COMMENT=	SMB/CIFS shares mounting scripts to do it at login

RUN_DEPENDS=	nbtscan:${PORTSDIR}/net-mgmt/nbtscan \
		sudo:${PORTSDIR}/security/sudo \

.if !exists(/usr/bin/host)
RUN_DEPENDS+=	host:${PORTSDIR}/dns/bind9
.endif

USE_BZIP2=	yes
NO_BUILD=	yes

do-install:

.for i in smb2nsmbrc mountsmb2
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	-@${MKDIR} ${EXAMPLESDIR}

.for i in sudoers .login .nsmbrc .mssmbrc nsmb.conf
	${INSTALL_DATA} ${WRKSRC}/${i} ${EXAMPLESDIR}
.endfor

	-@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.FreeBSD ${DOCSDIR}

	@${SED} -e "s,%%EXAMPLESDIR%%,${EXAMPLESDIR},g" ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
