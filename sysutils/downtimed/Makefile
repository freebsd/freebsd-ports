# Created by: Janne Snabb <snabb@epipe.com>
# $FreeBSD$

PORTNAME=	downtimed
PORTVERSION=	0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://dist.epipe.com/${PORTNAME}/ \
		http://launchpadlibrarian.net/145993356/

MAINTAINER=	snabb@epipe.com
COMMENT=	System downtime monitoring and reporting tool

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_XZ=		yes
MAN1=		downtimes.1
MAN8=		downtimed.8
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

post-install:
		@${MKDIR} /var/db/downtimed
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
