# New ports collection makefile for:	gnujsp
# Date created:		1999-07-15
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTNAME=	gnujsp
PORTVERSION=	1.0.1
CATEGORIES=	www java
MASTER_SITES=	http://www.klomp.org/gnujsp/downloads/

MAINTAINER=	girgen@partitur.se

RUN_DEPENDS=	${LOCALBASE}/libexec/apache/mod_jserv.so:${PORTSDIR}/www/apache-jserv

NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/MESSAGE

NO_BUILD=	yes  # use the prebuilt jar files

do-install:
		${MKDIR} ${PREFIX}/share/java/classes
		${INSTALL_DATA} ${WRKSRC}/lib/gnujsp10.jar ${WRKSRC}/lib/servlet-2.0-plus.jar \
			${PREFIX}/share/java/classes
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/examples/gnujsp
		@ cd ${WRKSRC}/examples ;\
			${INSTALL_DATA} date.jsp snoop.jsp hello.jsp ${PREFIX}/share/examples/gnujsp
		${MKDIR} ${PREFIX}/share/doc/gnujsp
.for file in CHANGES FAQ INSTALL.apache INSTALL.vqserver.html INSTALL.jigsaw README install.html
		${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gnujsp
.endfor
		@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${FILESDIR}/gnujsp.properties.in > \
			${PREFIX}/share/doc/gnujsp/gnujsp.properties
.endif

post-install:
		@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
