# New ports collection makefile for:	pdflib
# Date created:		Wed Jan 9 12:27:54 CET 2002
# Whom:			Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	pdflib
PORTVERSION=	7.0.5
CATEGORIES=	print perl java
MASTER_SITES=	http://www.pdflib.com/binaries/PDFlib/${PORTVERSION:S/.//g}/
DISTNAME=	PDFlib-Lite-${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A C library for dynamically generating PDF

RESTRICTED=	many odd restrictions on usage and distribution

.if defined(WITH_PERL)
OPTIONS=	PERL "Build perl bindings" on
.else
OPTIONS=	PERL "Build perl bindings" off
.endif
OPTIONS+=	JAVA "Build Java bindings" off

USE_LDCONFIG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-py=no --with-ruby=no --with-tcl=no

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64" || ${ARCH} == "sparc64"
CONFIGURE_ARGS+=--enable-64bit
.endif

.if defined(WITH_PERL)
USE_PERL5=	yes
PLIST_SUB=	PERL=""
CONFIGURE_ARGS+=--with-perl=${PERL}
.else
CONFIGURE_ARGS+=--with-perl=no
PLIST_SUB=	PERL="@comment "
.endif

.if defined(WITH_JAVA)
USE_JAVA=	yes
JAVA_BUILD=	yes
JAVA_RUN=	yes
PLIST_SUB+=	JAVA=""
CONFIGURE_ARGS+=--with-java=${JAVA_HOME}
.else
CONFIGURE_ARGS+=--with-java=no
PLIST_SUB+=	JAVA="@comment "
.endif

post-install:
	${MKDIR} ${DATADIR}/fonts
	${INSTALL_DATA} ${WRKSRC}/fonts/* ${DATADIR}/fonts
.if defined(WITH_JAVA)
 	${INSTALL_DATA} ${WRKSRC}/bind/pdflib/java/pdflib.jar ${JAVAJARDIR}/pdflib.jar
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/pdflib/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
