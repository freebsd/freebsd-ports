# Ports collection Makefile for:	esh
# Date created:				05/20/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	esh
PORTVERSION=	0.8.5
CATEGORIES=	shells
MASTER_SITES=	http://gd.tuwien.ac.at/opsys/linux/gentoo/distfiles/ \
		http://people.FreeBSD.org/~foxfair/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The "easy shell", a small shell with Lisp-like syntax

WRKSRC=		${WRKDIR}/esh
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I/usr/include/readline"
INFO=		esh

pre-build:
	@(cd ${WRKSRC} && ${MAKE} clean)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esh ${PREFIX}/bin/esh
	@${ECHO_MSG} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/esh /etc/shells.bak; \
	  ${ECHO_CMD} ${PREFIX}/bin/esh) > /etc/shells
	@${RM} /etc/shells.bak
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/doc/esh.info ${PREFIX}/info/esh.info
.endif

.include <bsd.port.mk>
