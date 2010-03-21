# New ports collection makefile for:	darkstat
# Date created:				24 February 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darkstat
PORTVERSION=	3.0.713
CATEGORIES=	net-mgmt
MASTER_SITES=	http://dmr.ath.cx/net/darkstat/

MAINTAINER=	emikulic@gmail.com
COMMENT=	Network statistics gatherer and reporter

USE_RC_SUBR=	darkstat

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN8=	darkstat.8
PORTDOCS=	AUTHORS INSTALL README
PLIST_FILES=	sbin/darkstat
.if !defined(NOPORTDOCS)
post-install:
	@${INSTALL} -d ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
