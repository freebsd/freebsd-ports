# Ports collection Makefile for:	esh
# Date created:				05/20/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	esh
PORTVERSION=	0.8
CATEGORIES=	shells
MASTER_SITES=	MASTER_SITE_LOCAL
MASTER_SITE_SUBDIR=

MAINTAINER=	nectar@FreeBSD.org

WRKSRC=		${WRKDIR}/esh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esh ${PREFIX}/bin/esh
	@${ECHO} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/esh /etc/shells.bak; \
	  ${ECHO} ${PREFIX}/bin/esh) > /etc/shells
	@${RM} /etc/shells.bak
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/doc/esh.info ${PREFIX}/info/esh.info
	install-info ${PREFIX}/info/esh.info ${PREFIX}/info/dir
.endif

.include <bsd.port.mk>
