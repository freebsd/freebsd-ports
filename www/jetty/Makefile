# New ports collection makefile for:	Jetty
# Date created:				28 August 2000
# Whom:				Stephane Legrand <stephane@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	jetty
PORTVERSION=	4.2.20
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://jetty.mortbay.com/pub/
MASTER_SITE_SUBDIR=	jetty
DISTFILES=	${PORTNAME}-${PORTVERSION}-all${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible Java HTTP Server

USE_JAVA=	1.2+

NO_BUILD=	yes

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
		${PREFIX}/share/java/${PORTNAME}-${PORTVERSION}/bin/jetty.sh
	@${LN} -sf \
		${PREFIX}/share/java/${PORTNAME}-${PORTVERSION}/bin/jetty.sh \
		${PREFIX}/sbin/jetty

.include <bsd.port.mk>
