# New ports collection makefile for:	javanns
# Date created:				7 January 2002
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	javanns
PORTVERSION=	1.0.b
CATEGORIES=	math java
MASTER_SITES=	http://www-ra.informatik.uni-tuebingen.de/downloads/JavaNNS/
DISTNAME=	JavaNNS-LinuxIntel

MAINTAINER=	des@FreeBSD.org

RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/javavmwrapper

JAVAVM?=	${LOCALBASE}/bin/javavm
CLASSDIR?=	${PREFIX}/share/java/classes
LIBSDIR?=	${DATADIR}/lib

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-configure:
	${INSTALL_DATA} ${FILESDIR}/javanns.sh ${WRKSRC}
	${PERL} -p -i -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/javanns.sh
	${PERL} -p -i -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/javanns.sh
	${PERL} -p -i -e 's|%%CLASSDIR%%|${CLASSDIR}|g' ${WRKSRC}/javanns.sh
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 0755

do-install:
	${MKDIR} ${DATADIR} ${DOCSDIR} ${LIBSDIR} ${CLASSDIR}
	${TAR} -cf - -C${WRKSRC} examples manual |\
	    ${TAR} -xf - -C${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/libSNNS_jkr.so ${LIBSDIR}
	${INSTALL_DATA} ${WRKSRC}/JavaNNSini.html ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/JavaNNS.jar ${CLASSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/javanns.sh ${PREFIX}/bin/javanns

.include <bsd.port.mk>
