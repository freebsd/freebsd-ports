# ex:ts=8
# Ports collection makefile for:  bk2site
# Date created:                   Wed Dec 06, 2000
# Whom:                           clive
#
# $FreeBSD$
#

PORTNAME=	bk2site
PORTVERSION=	1.1.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	clive@FreeBSD.org

USE_GMAKE=	yes
USE_AUTOCONF=	yes

post-patch:
	@${PERL} -pi -e 's,%PREFIX%,${PREFIX},' ${WRKSRC}/Makefile.in

pre-install:
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${CP} ${WRKSRC}/*.html ${WRKSRC}/dot.bk2siterc \
		${PREFIX}/etc/${PORTNAME}
	${MKDIR} ${PREFIX}/share/${PORTNAME}
	${CP} ${WRKSRC}/*.gif ${PREFIX}/share/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
