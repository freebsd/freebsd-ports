# New ports collection makefile for:	rsyncmanager
# Date created:				29 October 2004
# Whom:					Kelley Reynolds <kelley@insidesystems.net>
#
# $FreeBSD$
#

PORTNAME=	rsyncmanager
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.verbotenplanet.net/rsyncmanager/

MAINTAINER=	kelley@insidesystems.net
COMMENT=	Flexible rsync resource manager daemon written in ruby

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_RUBY=	yes
USE_RUBY_FEATURES=	1.8

NO_BUILD=	yes

PORTDOCS=	README

USE_RC_SUBR=	yes
SED_SCRIPT=	-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RUBY_WITHOUT_SUFFIX%%,${RUBY_WITHOUT_SUFFIX},g'

pre-install:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/${PORTNAME}.sh >${WRKDIR}/${PORTNAME}.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.rb ${PREFIX}/bin/${PORTNAME}.rb
	${INSTALL_DATA} ${WRKSRC}/examples/${PORTNAME}.xml ${PREFIX}/etc/${PORTNAME}.xml.sample
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/etc/rc.d/${PORTNAME}.sh
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
