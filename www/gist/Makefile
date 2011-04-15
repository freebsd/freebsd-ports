# New ports collection makefile for:	gist
# Date created:		2009-08-16
# Whom:			Ricky E. <codeblock@eighthbit.net>
#
# $FreeBSD$
#

PORTNAME=	gist
PORTVERSION=	2.0.1
CATEGORIES=	www net
MASTER_SITES=	https://github.com/defunkt/gist/raw/7340b581e0b7219f5fe39cea3ee7e9e8a653f2dc/
DISTNAME=	gist
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	codeblock@eighthbit.net
COMMENT=	A gist pastebin posting command

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

CONFLICTS=	p5-WWW-GitHub-Gist-[0-9]*

USE_RUBY=	YES
NO_BUILD=	YES
NO_WRKSUBDIR=	YES
PLIST_FILES=	bin/gist

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/gist ${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/gist ${PREFIX}/bin/gist

.include <bsd.port.mk>
