# New ports collection makefile for:	ramond
# Date created:				2010-01-25
# Whom:					janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	ramond
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/_${PORTVERSION}/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	On-link IPv6 router advertisement monitoring and reporting daemon

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_BZIP2=	YES
USE_GNOME=	libxml2
USE_RC_SUBR=	ramon

PORTDOCS=	README

.include <bsd.port.pre.mk>

LIB_DEPENDS+=	apr-1:${PORTSDIR}/devel/apr1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/gcc|${CC}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/main.c
	@${REINPLACE_CMD} -e 's|"/etc/|"${PREFIX}/etc/|g' ${WRKSRC}/src/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ramond ${PREFIX}/sbin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.dtd \
		${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/demo.pl \
		${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ramond.conf.example ${PREFIX}/etc/

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
