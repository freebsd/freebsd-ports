# New ports collection makefile for:	bash_completion
# Date created:				29 May 2003
# Whom:					kirk@strauser.com
#
# $FreeBSD$
#

PORTNAME=	bash-completion
PORTVERSION=	20040331
CATEGORIES=	shells
MASTER_SITES=	http://www.caliban.org/files/bash/

MAINTAINER=	kirk@strauser.com
COMMENT=	Programmable completion library for Bash 2.04 and up

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

.if defined(WITH_GSED)
RUN_DEPENDS+=	gsed:${PORTSDIR}/textproc/gsed
.endif

WRKSRC=		${WRKDIR}/bash_completion
NO_BUILD=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_FILES=	etc/bash_completion

pre-everything::
	@${ECHO}
	@${ECHO} "You can build ${PKGNAME} with the following options:"
	@${ECHO} "WITH_GSED	use GNU sed to enable additional completions"
	@${ECHO}

pre-patch:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message >${PKGMESSAGE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/bash_completion ${PREFIX}/etc/bash_completion

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
