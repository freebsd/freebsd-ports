# New ports collection makefile for:	rsyncbackup
# Date created:				8 October 2007
# Whom: 				Daniel Bond
#
# $FreeBSD$
#

PORTNAME=	rsyncbackup
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://rsync-backup.googlecode.com/files/
DISTNAME=	rsyncbackup

MAINTAINER=	ports@danielbond.org
COMMENT=	Rsync frontend written in Perl

RUN_DEPENDS=	rsync:${PORTSDIR}/net/rsync

CONFIGSRC=	${WRKSRC}/config
CONFIGFILES=	backupset.conf config.conf destinations.conf sources.conf

USE_ZIP=	yes
USE_PERL=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

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
