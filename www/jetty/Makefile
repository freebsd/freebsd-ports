# New ports collection makefile for:	Jetty
# Date created:				28 August 2000
# Whom:				Stephane Legrand <stephane.legrand@bigfoot.com>
#
# $FreeBSD$
#

PORTNAME=	jetty
PORTVERSION=	2.4.6
CATEGORIES=	www java
MASTER_SITES=	http://download.sourceforge.net/jetty/ \
		ftp://jetty.mortbay.com/pub/
DISTNAME=	Jetty-${PORTVERSION}

MAINTAINER=	stephane.legrand@bigfoot.com

RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jre

JAVAVM?=        ${LOCALBASE}/bin/javavm
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/java/${PORTNAME}
	@(cd ${WRKSRC} && ${TAR} -c -f - [^src]* ) \
		| (cd ${PREFIX}/share/java/${PORTNAME} && ${TAR} --unlink -x -f -)

post-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGMESSAGE}

.include <bsd.port.mk>
