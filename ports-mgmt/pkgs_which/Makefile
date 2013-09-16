# Created by: Matthias Andree <mandree@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pkgs_which
PORTVERSION=	0.3.0
CATEGORIES=	ports-mgmt perl5
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Quickly find out which ports contributed to a file tree

LICENSE=	GPLv3

USES=		perl5
NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
MAN1=		${PORTNAME}.1
.endif

do-install:
		${MKDIR} ${PREFIX}/bin
		${INSTALL_SCRIPT} ${FILESDIR}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
		${MKDIR} ${PREFIX}/man/man1
		${LOCALBASE}/bin/pod2man ${FILESDIR}/${PORTNAME} >${PREFIX}/man/man1/${MAN1}
.endif

.include <bsd.port.mk>
