# Created by: Craig Rodrigues <rodrigc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	serf
PORTVERSION=	1.2.0
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE
MASTER_SITE_SUBDIR=	db

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Serf HTTP client library

LIB_DEPENDS+=	apr-1:${PORTSDIR}/devel/apr1

MAKE_JOBS_SAFE=	yes

PROJECTHOST=	serf
USE_BZIP2=	yes
USE_GMAKE=	yes
USES=	pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=	--with-apr=${LOCALBASE}/bin/apr-1-config \
			--with-apr-util=${LOCALBASE}/bin/apu-1-config

post-patch:
	${REINPLACE_CMD} -e '/^Requires.private/d' ${WRKSRC}/serf.pc.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/design-guide.txt ${DOCSDIR}
.endif

check:
	@cd ${WRKSRC}/ && ${MAKE} check

.include <bsd.port.mk>
