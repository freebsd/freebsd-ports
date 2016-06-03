# Created by: Kelley Reynolds <kelley@insidesystems.net>
# $FreeBSD$

PORTNAME=	rsyncmanager
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.insidesystems.net/rsyncmanager/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible rsync resource manager daemon written in ruby

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

RUN_DEPENDS=	rsync:net/rsync

USE_RUBY=	yes

NO_BUILD=	yes

PLIST_FILES=	bin/rsyncmanager.rb etc/rsyncmanager.xml.sample
PORTDOCS=	README

USE_RC_SUBR=	${PORTNAME}
SUB_LIST=	RUBY_WITHOUT_SUFFIX="${RUBY_WITHOUT_SUFFIX}"

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME}.rb ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/documentation/${PORTNAME}.xml \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.xml.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
