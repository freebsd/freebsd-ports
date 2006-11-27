# New ports collection makefile for:	mod_security2
# Date created:				9 November 2006
# Whom:					Dominic Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	mod_security
PORTVERSION=	2.0.4
CATEGORIES=	www security
MASTER_SITES=	http://www.modsecurity.org/download/
DISTNAME=	${PORTNAME:S/_//}-apache_${PORTVERSION}

MAINTAINER=	dom@happygiraffe.net
COMMENT=	An intrusion detection and prevention engine

USE_APACHE=	2.0+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
MODULENAME=	mod_security2
WRKSRCTOP=	${WRKDIR}/${DISTNAME}
WRKSRC=		${WRKSRCTOP}/apache2
SRC_FILE=	*.c
PORTDOCS=	*
DOCS=		CHANGES LICENSE README.TXT modsecurity.conf-minimal doc
DOCSDIR=	${TARGETDIR}/share/doc/${MODULENAME}

.if defined(WITH_LIBXML2)
AP_EXTRAS+=	-DWITH_LIBXML2
AP_INC=		${LOCALBASE}/include/libxml2
AP_LIB=		${LOCALBASE}/lib
USE_GNOME=	libxml2
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRCTOP} && ${TAR} cf - ${DOCS}) | (cd ${DOCSDIR} && ${TAR} xpof -)
.endif

.include <bsd.port.mk>
