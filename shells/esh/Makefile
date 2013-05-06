# Created by: nectar@FreeBSD.org
# $FreeBSD$

PORTNAME=	esh
PORTVERSION=	0.8.5
CATEGORIES=	shells
MASTER_SITES=	GENTOO/distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The "easy shell", a small shell with Lisp-like syntax

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		readline
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
MAKE_JOBS_SAFE=	yes

INFO=		esh

post-patch:
	@${REINPLACE_CMD} -e \
		's|<readline.h>|<readline/readline.h>| ; \
		s|<history.h>|<readline/history.h>|' ${WRKSRC}/read-rl.c

pre-build:
	@(cd ${WRKSRC} && ${MAKE} clean)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esh ${PREFIX}/bin/esh
	@${ECHO_MSG} "updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/esh /etc/shells.bak; \
	  ${ECHO_CMD} ${PREFIX}/bin/esh) > /etc/shells
	@${RM} /etc/shells.bak
	${INSTALL_DATA} ${WRKSRC}/doc/esh.info ${PREFIX}/${INFO_PATH}

.include <bsd.port.mk>
