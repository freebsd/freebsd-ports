# Ports collection Makefile for:	esh
# Version required:			0.8
# Date created:				05/20/1999
# Whom:					nectar@FreeBSD.ORG
#
# $Id$
#

DISTNAME=		esh-0.8
CATEGORIES=		shells
MASTER_SITES=		http://esh.netpedia.net/                       \
			http://www.nectar.cc/distfiles/

MAINTAINER=		nectar@FreeBSD.ORG

WRKSRC=			${WRKDIR}/esh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esh ${PREFIX}/bin/esh
	@${ECHO} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/esh /etc/shells.bak;                \
	  ${ECHO} ${PREFIX}/bin/esh) > /etc/shells
	@${RM} /etc/shells.bak
.if !defined(NOPORTDOCS)
	if [ -f ${PREFIX}/info/dir ]; then                             \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir >                \
	    ${PREFIX}/info/dir;                                        \
	fi
	${INSTALL_DATA} ${WRKSRC}/doc/esh.info ${PREFIX}/info/esh.info
	install-info ${PREFIX}/info/esh.info ${PREFIX}/info/dir
.endif

.include <bsd.port.mk>
