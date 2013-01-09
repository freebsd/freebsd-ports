# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	slbd
PORTVERSION=	1.3
CATEGORIES=	net sysutils
MASTER_SITES=	SF

MAINTAINER=	jmohacsi@bsd.hu
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

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800502
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
