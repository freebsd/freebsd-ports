# New ports collection makefile for:	phpnuke
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	phpnuke
PORTVERSION=	4.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpnuke
DISTNAME=	PHP-Nuke-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
DOCS=		BUGS CHANGES README TODO

do-install:
	${MKDIR} ${PREFIX}/www/phpnuke/html
	${CP} -Rp ${WRKDIR}/html ${WRKDIR}/sql ${PREFIX}/www/phpnuke
.if !defined(NOPORTDOCS)
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKDIR}/${FILE} ${PREFIX}/www/phpnuke
.endfor
.endif

.include <bsd.port.mk>
