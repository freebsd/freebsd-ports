# New ports collection makefile for:	postnuke
# Date created:				14 July 2002
# Whom:					Tae-seong Kim <rapzzard@rapzzard.pe.kr>
#
# $FreeBSD$
#

PORTNAME=	postnuke
PORTVERSION=	0.761
CATEGORIES=	www
MASTER_SITES=	http://downloads.postnuke.com/sf/postnuke/
DISTNAME=	PostNuke-0.761

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automated website package to distribute and manage content

RUN_DEPENDS=	${LOCALBASE}/share/pear/System.php:${PORTSDIR}/devel/pear

USE_MYSQL=	YES

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/PostNuke-0.761
NO_WRKSUBDIR=	yes
PLIST_SUB=	NUKEDIR=${NUKEDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

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
	@${MKDIR} ${PREFIX}/${NUKEDIR}/phoenix-sql
	@${CP} -Rp ${WRKSRC}/html ${WRKSRC}/phoenix-sql ${PREFIX}/${NUKEDIR}

post-install:
	@${CHMOD} 644 ${PREFIX}/${NUKEDIR}/html/config*.php
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
