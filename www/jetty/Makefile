# New ports collection makefile for:	Jetty
# Date created:				28 August 2000
# Whom:				Stephane Legrand <stephane@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	jetty
DISTVERSION=	5.1.11RC0
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jetty
DISTNAME=	${PORTNAME}-${DISTVERSION}-all

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible Java HTTP Server

USE_ZIP=	yes
JAVA_BUILD=	jdk
USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PLIST_SUB=	JETTY_VERSION=${PORTVERSION}

post-extract:
	${FIND} ${WRKSRC} -name CVS -delete
	${FIND} ${WRKSRC} -name .cvsignore -delete

do-install:
	@${MKDIR} ${PREFIX}/share/java/${PORTNAME}-${PORTVERSION}
	@(cd ${WRKSRC} && ${TAR} -c --exclude 'src/*' -f - ./ ) \
		| (cd ${PREFIX}/share/java/${PORTNAME}-${PORTVERSION} && ${TAR} --unlink -x -f -)

post-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGMESSAGE} \
		| ${SED} 's|%%PORTVERSION%%|${PORTVERSION}|g'
	@${CHMOD} a+rx \
		${PREFIX}/share/java/${PORTNAME}-${PORTVERSION}/extra/unix/bin/jetty.sh
	@${LN} -sf \
		${PREFIX}/share/java/${PORTNAME}-${PORTVERSION}/extra/unix/bin/jetty.sh \
		${PREFIX}/sbin/jetty

.include <bsd.port.mk>
