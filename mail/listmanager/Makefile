# New ports collection makefile for:	listmanager
# Date created:				29 Dec 1999
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	listmanager
PORTVERSION=	2.109
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.listmanager.org/v${PORTVERSION}/ \
		http://www.listmanager.org/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.freebsd44
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} INSTALL help.tar.gz listmanager.8 ack
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	gshapiro@FreeBSD.org
COMMENT=	Fully-featured mailing list manager

LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}
PKGMESSAGE=	${WRKSRC}/pkg-message
MAN8=		listmanager.8

LISTMANAGER_HOME?=/var/listmanager
MTAGRP?=	mailnull

pre-patch:
	(cd ${WRKSRC} && ${TAR} xfz help.tar.gz)

post-patch:
	@ for f in listmanager.cf pkg-message setup; do \
		${SED}	-e "s|@@VARPREFIX@@|${LISTMANAGER_HOME}|g" \
			-e "s|@@INSPREFIX@@|${PREFIX}|g" \
			 < ${FILESDIR}/$$f.in > ${WRKSRC}/$$f; \
	done

do-install:
	@${MKDIR} ${PREFIX}/etc
	@${MKDIR} ${PREFIX}/share/listmanager/help
	${INSTALL_DATA} ${WRKSRC}/listmanager.cf ${PREFIX}/etc/listmanager.cf.sample
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/listmanager
	${INSTALL_DATA} ${WRKSRC}/ack ${PREFIX}/share/listmanager
	${INSTALL_DATA} ${WRKSRC}/help/* ${PREFIX}/share/listmanager/help
	${INSTALL_SCRIPT} ${WRKSRC}/setup ${PREFIX}/share/listmanager
	${INSTALL_MAN} ${WRKSRC}/listmanager.8 ${PREFIX}/man/man8
	${INSTALL_PROGRAM} -g ${MTAGRP} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} ${PREFIX}/sbin/listmanager
	${CHMOD} 4510 ${PREFIX}/sbin/listmanager

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
