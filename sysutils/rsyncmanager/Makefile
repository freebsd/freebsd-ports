# Created by: Kelley Reynolds <kelley@insidesystems.net>
# $FreeBSD$

PORTNAME=	rsyncmanager
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.insidesystems.net/rsyncmanager/

MAINTAINER=	kelley@insidesystems.net
COMMENT=	Flexible rsync resource manager daemon written in ruby

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

USE_RUBY=	yes
USE_RUBY_FEATURES=	ruby18

NO_BUILD=	yes

PORTDOCS=	README

USE_RC_SUBR=	${PORTNAME}
SUB_LIST=	RUBY_WITHOUT_SUFFIX="${RUBY_WITHOUT_SUFFIX}"

NO_STAGE=	yes
post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME}.rb ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/documentation/${PORTNAME}.xml ${PREFIX}/etc/${PORTNAME}.xml.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/documentation/${docfile} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
