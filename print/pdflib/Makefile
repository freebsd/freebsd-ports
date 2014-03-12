# Created by: Alex Dupre <sysadmin@alexdupre.com>
# $FreeBSD$

PORTNAME=	pdflib
PORTVERSION=	7.0.5
PORTREVISION=	2
CATEGORIES=	print perl5 java
MASTER_SITES=	http://www.pdflib.com/binaries/PDFlib/${PORTVERSION:S/.//g}/
DISTNAME=	PDFlib-Lite-${PORTVERSION}p3

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A C library for dynamically generating PDF

RESTRICTED=	many odd restrictions on usage and distribution

OPTIONS_DEFINE=	PERL JAVA
PERL_DESC=	Build perl bindings
JAVA_DESC=	Build Java bindings

USES=		gmake
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-py=no --with-ruby=no --with-tcl=no

PORTDOCS=	*

NO_STAGE=	yes
PERL_USES=	perl5

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64" || ${ARCH} == "sparc64"
CONFIGURE_ARGS+=--enable-64bit
.endif

.if ${PORT_OPTIONS:MPERL}
PLIST_SUB=	PERL=""
CONFIGURE_ARGS+=--with-perl=${PERL}
.else
CONFIGURE_ARGS+=--with-perl=no
PLIST_SUB=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MJAVA}
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
.if ${PORT_OPTIONS:MJAVA}
	${INSTALL_DATA} ${WRKSRC}/bind/pdflib/java/pdflib.jar ${JAVAJARDIR}/pdflib.jar
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/pdflib/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
