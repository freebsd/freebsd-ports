# New ports collection makefile for:	Jetty
# Date created:				28 August 2000
# Whom:				Stephane Legrand <stephane@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	jetty
PORTVERSION=	4.1.3
CATEGORIES=	www java
MASTER_SITES=	http://download.sourceforge.net/jetty/ \
		ftp://jetty.mortbay.com/pub/
DISTNAME=	Jetty-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	stephane@freebsd-fr.org

USE_JAVA=	1.3+

NO_BUILD=	yes

PLIST_SUB=	JETTY_VERSION=${PORTVERSION}

post-extract:
	${FIND} ${WRKSRC} -name CVS -delete
	${FIND} ${WRKSRC} -name .cvsignore -delete

do-install:
	@${MKDIR} ${PREFIX}/share/java/${PORTNAME}-${PORTVERSION}
	@(cd ${WRKSRC} && ${TAR} -c --exclude 'src/*' --exclude 'src1.4/*' -f - ./ ) \
		| (cd ${PREFIX}/share/java/${PORTNAME}-${PORTVERSION} && ${TAR} --unlink -x -f -)

post-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGMESSAGE} \
		| ${SED} 's|%%PORTVERSION%%|${PORTVERSION}|g'

.include <bsd.port.mk>
