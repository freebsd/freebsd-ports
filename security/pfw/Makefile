# New ports collection makefile for:	pfw
# Date created:		2005-04-14
# Whom:			Renato Botelho <freebsd@galle.com.br>
#
# $FreeBSD$
#

PORTNAME=	pfw
PORTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	http://www.allard.nu/pfw/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A web frontend for the pf firewall

RUN_DEPENDS=	sudo:${PORTSDIR}/security/sudo

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PHP=	session	pcre sqlite
WANT_PHP_WEB=	yes
DEFAULT_PHP_VER=5
BROKEN_WITH_PHP=4
NO_BUILD=	yes

PFW_PREFIX?=	${PREFIX}/www/pfw
SUB_FILES=	pkg-message
SUB_LIST=	PFW_PREFIX=${PFW_PREFIX}

BINFILES=	commandwrapper.sh packetfilter.sh
CPDIRS=		lib web include test
PORTDOCS=	INSTALL README README_TEST

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502105
IGNORE=		pf is only in 5.x and newer
.endif

do-install:
	${MKDIR} ${PFW_PREFIX}
	${INSTALL_DATA} ${WRKSRC}/include.inc.php ${PFW_PREFIX}
.for dir in ${CPDIRS}
	@${MKDIR} ${PFW_PREFIX}/${dir}
	@${CP} -Rv ${WRKSRC}/${dir}/* ${PFW_PREFIX}/${dir}
.endfor
	@${MKDIR} ${PFW_PREFIX}/bin
.for f in ${BINFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${PFW_PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/docs/sql/sqlite.sql ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
. endfor
.endif
	${MKDIR} ${PFW_PREFIX}/conf
	${CHOWN} www:www ${PFW_PREFIX}/conf

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
