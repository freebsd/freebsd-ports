# New ports collection makefile for:	wmmemmon
# Date created:				Wed May  9 17:55:21 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmmemmon
PORTVERSION=	0.5.2
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.sh.rim.or.jp/~ssato/src/
DISTNAME=	WMMemMon-${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes

pre-patch:
	@${PERL} -pi.orig -e 's|WMMwmMon|WMMemMon|' \
		${WRKSRC}/src/wmmemmon.c

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif # !NOPORTDOCS

.include <bsd.port.mk>
