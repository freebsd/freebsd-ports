# New ports collection makefile for: serf
# Date created:		28 May 2008
# Whom:			Craig Rodrigues <rodrigc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	serf
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Serf HTTP client library

LIB_DEPENDS+=	apr-1:${PORTSDIR}/devel/apr1

MAKE_JOBS_SAFE=  yes

PROJECTHOST=	serf
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=	--with-apr=${LOCALBASE}/bin/apr-1-config \
			--with-apr-util=${LOCALBASE}/bin/apu-1-config

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/design-guide.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
