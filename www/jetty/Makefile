# New ports collection makefile for:	Jetty
# Date created:				28 August 2000
# Whom:				Stephane Legrand <stephane.legrand@bigfoot.com>
#
# $FreeBSD$
#

PORTNAME=	jetty
PORTVERSION=	3.1.4
CATEGORIES=	www java
MASTER_SITES=	http://download.sourceforge.net/jetty/ \
		ftp://jetty.mortbay.com/pub/
DISTNAME=	Jetty-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	stephane.legrand@bigfoot.com

RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jdk13

JAVAVM?=	${LOCALBASE}/bin/javavm
NO_BUILD=	yes

PLIST_SUB=      JETTY_VERSION=${PORTVERSION}

post-extract:
	find ${WRKSRC} -name CVS -delete
	find ${WRKSRC} -name .cvsignore -delete

do-install:
	@${MKDIR} ${PREFIX}/share/java/${PORTNAME}-${PORTVERSION}
	@(cd ${WRKSRC} && ${TAR} -c -f - [^src]* ) \
		| (cd ${PREFIX}/share/java/${PORTNAME}-${PORTVERSION} && ${TAR} --unlink -x -f -)

post-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGMESSAGE} \
		| ${SED} 's|%%PORTVERSION%%|${PORTVERSION}|g'

.include <bsd.port.mk>
