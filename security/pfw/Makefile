# New ports collection makefile for:	pfw
# Date created:		2005-04-14
# Whom:			Renato Botelho <freebsd@galle.com.br>
#
# $FreeBSD$
#

PORTNAME=	pfw
PORTVERSION=	0.5.3
CATEGORIES=	security www
MASTER_SITES=	http://www.allard.nu/pfw/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	freebsd@galle.com.br
COMMENT=	A web frontend for the pf firewall

RUN_DEPENDS=	sudo:${PORTSDIR}/security/sudo

USE_PHP=	session	pcre
WANT_PHP_WEB=	yes
NO_BUILD=	yes

PFW_PREFIX?=	${PREFIX}/www/pfw
SUB_FILES=	pkg-message
SUB_LIST=	PFW_PREFIX=${PFW_PREFIX}
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		"pf is only in 5.x"
.elif ${OSVERSION} < 502105
RUN_DEPENDS+=	pf:${PORTSDIR}/security/pf
.endif

do-install:
	@${MKDIR} ${PFW_PREFIX} ${PFW_PREFIX}/bin ${PFW_PREFIX}/lib ${PFW_PREFIX}/web
	@${CP} -v ${WRKSRC}/INSTALL ${WRKSRC}/README ${PFW_PREFIX}
	@${CP} -Rv ${WRKSRC}/web/* ${PFW_PREFIX}/web
	@${CP} -Rv ${WRKSRC}/lib/* ${PFW_PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/bin/pfctlwrapper.sh.remote ${PFW_PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/pfctlwrapper.sh ${PFW_PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
