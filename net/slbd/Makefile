# New ports collection makefile for:   slbd
# Date created:        30 October 2006
# Whom:                Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	slbd
PORTVERSION=	1.3
CATEGORIES=	net sysutils
MASTER_SITES=	SF

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Server load balancing daemon for *BSD pf

PLIST_FILES=	sbin/slbd etc/slbdcap-sample
PORTDOCS=	configfile.txt

post-patch:
	@${REINPLACE_CMD} -e "s;%%PREFIX%%;${PREFIX};g" \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
