# New ports collection makefile for:   portless
# Date created:        8 June 2006
# Whom:                Martin Kammerhofer
#
# $FreeBSD$
#

PORTNAME=	portless
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	mkamm@gmx.net
COMMENT=	Quick display of files inside the FreeBSD ports tree

RUN_DEPENDS=	less:${PORTSDIR}/sysutils/less

NO_BUILD=	yes
MAN1=		portless.1
MANCOMPRESSED=	no

PLIST_FILES=	bin/portless

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/portless.sh ${PREFIX}/bin/portless
	${INSTALL_MAN} ${FILESDIR}/portless.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
