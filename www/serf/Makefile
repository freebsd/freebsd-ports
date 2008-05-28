# New ports collection makefile for: apr
# Date created:		28 May 2008
# Whom:			Craig Rodrigues <rodrigc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	serf
PORTVERSION=	0.1.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	rodrigc@FreeBSD.org
COMMENT=	Serf HTTP client library

LIB_DEPENDS+=	apr:${PORTSDIR}/devel/apr

PROJECTHOST=	serf
PORTDOCS=	design-guide.txt
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=	--with-apr=${PREFIX}/bin/apr-1-config \
			--with-apr-util=${PREFIX}/bin/apu-1-config

post-install:
	${MKDIR} ${DOCSDIR}
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/design-guide.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
