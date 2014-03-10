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

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

	${MKDIR} ${ETCDIR}
.for configfile in ${CONFIGFILES}
	${INSTALL_DATA} ${CONFIGSRC}/${configfile} ${ETCDIR}/${configfile}.example
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
