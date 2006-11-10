# New ports collection makefile for:   slbd
# Date created:        30 October 2006
# Whom:                Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	slbd
PORTVERSION=	1.3
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

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

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502106
IGNORE=	is of no use for you because your system is too old and doesn't have pf
.endif

.include <bsd.port.post.mk>
