# New ports collection makefile for:	gnujsp
# Version required:	0.9.10
# Date created:		1999-07-15
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

DISTNAME=	gnujsp-0.9.10
CATEGORIES=	www java
MASTER_SITES=	http://www.klomp.org/gnujsp/09x/

MAINTAINER=	girgen@partitur.se

RUN_DEPENDS=	${PREFIX}/share/java/classes/jsdk.jar:${PORTSDIR}/java/jsdk

NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/MESSAGE

do-install:
		${MKDIR} ${PREFIX}/share/java/classes
		${INSTALL_DATA} ${WRKSRC}/lib/gnujsp.jar ${PREFIX}/share/java/classes
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/examples/gnujsp/org/gjt/vinny/beans
.for file in date.jsp mailform.html sendmail.jsp \
		session.jsp snoop.jsp \
		org/gjt/vinny/beans/MailBean.java \
		org/gjt/vinny/beans/MailBean.class
		@ cd ${WRKSRC}/examples ;\
		 ${INSTALL_DATA} ${file} \
		 ${PREFIX}/share/examples/gnujsp/`dirname ${file}`
.endfor
		${MKDIR} ${PREFIX}/share/doc/gnujsp
.for file in CHANGES INSTALL README
		${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gnujsp
.endfor
.endif

post-install:
		@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGDIR}/MESSAGE > ${PKGMESSAGE}
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
