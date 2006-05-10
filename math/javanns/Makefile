# New ports collection makefile for:	javanns
# Date created:				7 January 2002
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	javanns
PORTVERSION=	1.1
CATEGORIES=	math java
MASTER_SITES=	http://www-ra.informatik.uni-tuebingen.de/downloads/JavaNNS/
DISTNAME=	JavaNNS-LinuxIntel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fully featured neural network simulator

RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/javavmwrapper

ONLY_FOR_ARCHS=	i386

JAVAVM?=	${LOCALBASE}/bin/javavm
CLASSDIR?=	${PREFIX}/share/java/classes
LIBSDIR?=	${DATADIR}/lib

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

post-extract:
	# Permissions in the tar file are whacked
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 755
	${FIND} ${WRKSRC} -type f -print | ${XARGS} ${CHMOD} 644

do-configure:
	${INSTALL_DATA} ${FILESDIR}/javanns.sh ${WRKSRC}
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
			-e 's|%%DATADIR%%|${DATADIR}|g' \
			-e 's|%%CLASSDIR%%|${CLASSDIR}|g' ${WRKSRC}/javanns.sh
	${FIND} ${WRKSRC} -type d -print | ${XARGS} ${CHMOD} 0755

do-install:
	${MKDIR} ${DATADIR} ${LIBSDIR} ${CLASSDIR}
	${INSTALL_DATA} ${WRKSRC}/JavaNNS.jar ${CLASSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/javanns.sh ${PREFIX}/bin/javanns
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	${TAR} -cf - -C${WRKSRC} examples manual |\
	    ${TAR} -xf - -C${DOCSDIR}
.endif

.include <bsd.port.mk>
