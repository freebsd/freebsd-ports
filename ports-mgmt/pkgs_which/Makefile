# New ports collection makefile for:	pkgs_which
# Date created:				12 March 2011
# Whom:					Matthias Andree <mandree@FreeBSD.org>
#
# $FreeBSD$
#
# This port is self contained in the files directory.
#

PORTNAME=	pkgs_which
PORTVERSION=	0.1.0
CATEGORIES=	ports-mgmt perl5
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Quickly find out which ports contributed to a file tree

LICENSE=	GPLv3

NO_BUILD=	yes
USE_PERL5=	yes
PLIST_FILES=	bin/${PORTNAME}

.if !defined(NOPORTDOCS)
MAN1=		${PORTNAME}.1
.endif

do-install:
		${MKDIR} ${PREFIX}/bin
		${INSTALL_SCRIPT} ${FILESDIR}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/man/man1
		${LOCALBASE}/bin/pod2man ${FILESDIR}/${PORTNAME} >${PREFIX}/man/man1/${MAN1}
.endif

.include <bsd.port.mk>
