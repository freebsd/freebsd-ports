# New ports collection makefile for:   XawPlus
# Date created:        30 January 2003
# Whom:                DNPM <freebsd@falx.port5.com>
#
# $FreeBSD$
#

PORTNAME=	XawPlus
PORTVERSION=	3.1.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://people.freenet.de/kra/XawPlus/
DISTNAME=	${PORTNAME:L}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A replacement for Xaw with a nicer 3-D look and some extensions

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%X11BASE%%/lib

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@cd ${WRKSRC} && ${FIND} . -name '*.orig' -delete

do-configure:
	${REINPLACE_CMD} -e 's:%%X11BASE%%:${X11BASE}:' ${WRKSRC}/test/Makefile
	-@${RM} -f ${WRKSRC}/test/Makefile.bak

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
