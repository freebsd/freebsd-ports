# New ports collection makefile for:   mod_antiloris
# Date created:		20 August 2009
# Whom:			Aleksandar Pejic <alex@vts.su.ac.rs>
#
# $FreeBSD$
#

PORTNAME=	mod_antiloris
PORTVERSION=	0.4
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.monshouwer.eu/pub/linux/mod_antiloris/

MAINTAINER=	alex@vts.su.ac.rs
COMMENT=	Protect Apache 2.x against the Slowloris HTTP DoS attack

MAKE_JOBS_SAFE=	yes

USE_BZIP2=	yes
USE_APACHE=	20+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_EXTRAS+=	-a
MODULENAME=	mod_antiloris
SRC_FILE=	*.c
SUB_FILES+=	mod_antiloris.conf
SUB_LIST+=	APACHEETCDIR="${APACHEETCDIR}"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.if !defined(SKIP_RULES)
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_antiloris.conf
SUB_FILES+=	pkg-message.rules
.endif

post-install:
.if !defined(SKIP_RULES)
	@${INSTALL_DATA} ${WRKDIR}/mod_antiloris.conf ${PREFIX}/${APACHEETCDIR}/Includes/
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
