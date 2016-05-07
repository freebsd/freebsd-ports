# Created by: Kelley Reynolds <kelley@insidesystems.net>
# $FreeBSD$

PORTNAME=	daedalus
PORTVERSION=	2.0.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.insidesystems.net/daedalus/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible process monitor/restart daemon written in ruby

BROKEN=		unfetchable

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_RUBY=	yes

NO_BUILD=	yes

SED_SCRIPT=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RUBY_WITHOUT_SUFFIX%%,${RUBY_WITHOUT_SUFFIX},g'

pre-install:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/${PORTNAME}.sh >${WRKDIR}/${PORTNAME}.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/daedalus.rb ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/daedalus.xml \
		${STAGEDIR}${ETCDIR}/daedalus.xml.sample
	${INSTALL_DATA} ${WRKSRC}/examples/templates.xml \
		${STAGEDIR}${ETCDIR}/templates.xml.sample
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/etc/rc.d/${PORTNAME}.sh

.include <bsd.port.mk>
