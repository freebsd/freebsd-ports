# New ports collection makefile for:	daedalus
# Date created:				16 June 2004
# Whom:					Kelley Reynolds <kelley@insidesystems.net>
#
# $FreeBSD$
#

PORTNAME=	daedalus
PORTVERSION=	2.0.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.insidesystems.net/daedalus/

MAINTAINER=	kelley@insidesystems.net
COMMENT=	Flexible process monitor/restart daemon written in ruby

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_RUBY=	yes
USE_RUBY_FEATURES=	1.8

NO_BUILD=	yes

USE_RC_SUBR=	yes
SED_SCRIPT=	-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RUBY_WITHOUT_SUFFIX%%,${RUBY_WITHOUT_SUFFIX},g'

pre-install:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/${PORTNAME}.sh >${WRKDIR}/${PORTNAME}.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/daedalus.rb ${PREFIX}/bin/daedalus.rb
	${MKDIR} ${PREFIX}/etc/daedalus
	${INSTALL_DATA} ${WRKSRC}/examples/daedalus.xml ${PREFIX}/etc/daedalus/daedalus.xml.sample
	${INSTALL_DATA} ${WRKSRC}/examples/templates.xml ${PREFIX}/etc/daedalus/templates.xml.sample
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/etc/rc.d/${PORTNAME}.sh

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
