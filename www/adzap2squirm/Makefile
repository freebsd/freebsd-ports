# New ports collection makefile for:	adzap2squirm
# Date created:				02 Sept 2003
# Whom:					Robert Muir <rmuir@radford.edu>
#
# $FreeBSD$
#

PORTNAME=	adzap2squirm
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	http://www.meredevice.com/files/  \
		http://adzapper.sourceforge.net/scripts/
DISTFILES=	adzap2squirm a2swrap update-zapper
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Use and update adzap patterns with squirm

RUN_DEPENDS=	squirm:${PORTSDIR}/www/squirm

SQUID_UID?=	squid
SQUID_GID?=	squid
MAKE_ENV+=	SQUID_UID=${SQUID_UID} SQUID_GID=${SQUID_GID}

USE_REINPLACE=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/pkg-message ${PKGMESSAGE}
.for DISTFILE in ${DISTFILES}
	${CP} ${DISTDIR}/${DISTFILE} ${WRKSRC}
.endfor

post-patch:
	${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/a2swrap
	${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGMESSAGE}
	${REINPLACE_CMD} \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		-e "s,%%FETCH_CMD%%,${FETCH_CMD},g" \
		${WRKSRC}/update-zapper

do-install:
.for DISTFILE in ${DISTFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTFILE} ${PREFIX}/bin
.endfor
	${INSTALL} ${FILESDIR}/squirm.conf.zap ${PREFIX}/etc/squirm/
	${TOUCH} ${PREFIX}/etc/squirm/zap.patterns
	${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>
