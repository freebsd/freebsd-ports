# Created by: Daniel Bond
# $FreeBSD$

PORTNAME=	rsyncbackup
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	rsyncbackup

MAINTAINER=	ports@danielbond.org
COMMENT=	Rsync frontend written in Perl

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

PROJECTHOST=	rsync-backup
CONFIGSRC=	${WRKSRC}/config
CONFIGFILES=	backupset.conf config.conf destinations.conf sources.conf

USES=		perl5 zip
NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.for configfile in ${CONFIGFILES}
	${INSTALL_DATA} ${CONFIGSRC}/${configfile} \
		${STAGEDIR}${ETCDIR}/${configfile}.example
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
