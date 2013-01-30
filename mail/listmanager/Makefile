# Created by: will
# $FreeBSD$

PORTNAME=	listmanager
PORTVERSION=	2.109
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.listmanager.org/v${PORTVERSION}/ \
		http://www.listmanager.org/
DISTNAME=	${PORTNAME}
DISTFILES=	listmanager.freebsd44 INSTALL help.tar.gz listmanager.8 ack
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	gshapiro@FreeBSD.org
COMMENT=	Fully-featured mailing list manager

DEPRECATED=	No more upstream, no more public distfiles
EXPIRATION_DATE=	2013-03-01

LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}
SUB_FILES=	listmanager.cf pkg-message setup
SUB_LIST=	LISTMANAGER_HOME=${LISTMANAGER_HOME}
MAN8=		listmanager.8

LISTMANAGER_HOME?=/var/listmanager
MTAGRP?=	mailnull

pre-patch:
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC} && ${TAR} xfz help.tar.gz)
.endif

do-install:
	@${MKDIR} ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/listmanager.cf ${PREFIX}/etc/listmanager.cf.sample
.if !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/setup ${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/help
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ack ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/help/* ${DOCSDIR}/help
.endif
	${INSTALL_MAN} ${WRKSRC}/listmanager.8 ${PREFIX}/man/man8
	${INSTALL_PROGRAM} -g ${MTAGRP} ${WRKSRC}/listmanager.freebsd44 ${PREFIX}/sbin/listmanager
	${CHMOD} 4510 ${PREFIX}/sbin/listmanager

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
