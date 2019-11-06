# Created by: Janos Mohacsi <janos.mohacsi@dante.org.uk>
# $FreeBSD$

PORTNAME=	www6to4
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Lightweight http proxy to help IPv4 only browsers

BROKEN=		unfetchable

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/./-/}

USE_RC_SUBR=	www6to4

PORTDOCS=	README

ALL_TARGET=	www6to4

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${ETCDIR},' \
		${WRKSRC}/www6to4.c ${WRKSRC}/www6to4.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/www6to4 ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/www6to4.conf \
		${STAGEDIR}${ETCDIR}/www6to4.conf.sample
	${INSTALL_DATA} ${WRKSRC}/www6to4_forward.conf \
		${STAGEDIR}${ETCDIR}/www6to4_forward.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
