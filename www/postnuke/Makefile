# New ports collection makefile for:	postnuke
# Date created:				14 July 2002
# Whom:					Tae-seong Kim <rapzzard@rapzzard.pe.kr>
#
# $FreeBSD$
#

PORTNAME=	postnuke
PORTVERSION=	0.714
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	post-nuke
DISTNAME=	Rogue_714

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automated website package to distribute and manage content

RUN_DEPENDS=	${LOCALBASE}/share/pear/System.php:${PORTSDIR}/devel/pear-PEAR

USE_MYSQL=	YES

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/pn_714
NO_WRKSUBDIR=	yes
DOCFILES=	README-FIRST.txt THEME_UPGRADES.txt UPGRADE.txt pnAPI.pdf pnMDG.pdf
PLIST_SUB=	NUKEDIR=${NUKEDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_REINPLACE=	yes

pre-fetch:
.if !defined(NUKEDIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define NUKEDIR to override default of 'www/data/postnuke'."
	@${ECHO_MSG} ""
.endif

NUKEDIR?=	www/data/postnuke

post-configure:
	${CP} pkg-message ${PKGMESSAGE}
	${REINPLACE_CMD} \
		-e 's#%%PREFIX%%#${PREFIX}#g' \
		-e 's#%%NUKEDIR%%#${NUKEDIR}#g' ${PKGMESSAGE}

do-install:
	@${MKDIR} ${PREFIX}/${NUKEDIR}
	@${MKDIR} ${PREFIX}/${NUKEDIR}/html
	@${MKDIR} ${PREFIX}/${NUKEDIR}/sql
	@${CP} -Rp ${WRKSRC}/html ${WRKSRC}/sql ${PREFIX}/${NUKEDIR}

post-install:
	@${CHMOD} 644 ${PREFIX}/${NUKEDIR}/html/config*.php
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
.endif
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
