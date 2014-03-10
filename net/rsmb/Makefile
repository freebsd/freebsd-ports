# Created by: Andrew Stevenson <andrew@ugh.net.au>
# $FreeBSD$

PORTNAME=	rsmb
PORTVERSION=	1.1.0
CATEGORIES=	net linux
MASTER_SITES=	#
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	andrew@ugh.net.au
COMMENT=	Really Small Message Broker, an MQTT supporting server

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		zip
USE_LINUX=	yes
LINUX_OSRELEASE=2.6.16
IA32_BINARY_PORT=	yes
RESTRICTED=	\nPlease visit http://www.alphaworks.ibm.com/tech/rsmb/download
RESTRICTED+=	\nto register for an account, agree to the license and download
RESTRICTED+=	\n${DISTFILES}.
RESTRICTED+=	\nMove the file to ${DISTDIR} and restart the build.\n\n
USE_RC_SUBR=	rsmbd
PLIST_SUB=	PORTVERSION=${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
ECHO_MSG=	${PRINTF}
IGNORE=		${RESTRICTED}
.endif

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/gettingstarted.htm ${DOCSDIR}
.endif
	${MKDIR} ${PREFIX}/libexec/rsmb
	${INSTALL_PROGRAM} ${WRKSRC}/broker.redhat ${PREFIX}/libexec/rsmb/broker
	${INSTALL_DATA} ${WRKSRC}/Messages.${PORTVERSION} ${PREFIX}/libexec/rsmb/
	${INSTALL_DATA} ${FILESDIR}/broker.cfg ${PREFIX}/etc/broker.cfg.dist

.include <bsd.port.post.mk>
