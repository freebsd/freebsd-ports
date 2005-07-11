# New ports collection makefile for:	pfw
# Date created:		2005-04-14
# Whom:			Renato Botelho <freebsd@galle.com.br>
#
# $FreeBSD$
#

PORTNAME=	pfw
PORTVERSION=	0.6.2
CATEGORIES=	security www
MASTER_SITES=	http://www.allard.nu/pfw/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A web frontend for the pf firewall

RUN_DEPENDS=	sudo:${PORTSDIR}/security/sudo

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PHP=	session	pcre
WANT_PHP_WEB=	yes
NO_BUILD=	yes

PFW_PREFIX?=	${PREFIX}/www/pfw
SUB_FILES=	pkg-message
SUB_LIST=	PFW_PREFIX=${PFW_PREFIX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		pf is only in 5.x
.elif ${OSVERSION} < 502105
RUN_DEPENDS+=	pf:${PORTSDIR}/security/pf
.endif

do-install:
.for dir in lib web
	@${MKDIR} ${PFW_PREFIX}/${dir}
	@${CP} -Rv ${WRKSRC}/${dir}/* ${PFW_PREFIX}/${dir}
.endfor
	@${CP} -v ${WRKSRC}/INSTALL ${WRKSRC}/README ${PFW_PREFIX}
	@${MKDIR} ${PFW_PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/pfctlwrapper.sh.remote ${PFW_PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/pfctlwrapper.sh ${PFW_PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
