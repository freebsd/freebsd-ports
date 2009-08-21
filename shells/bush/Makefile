# New ports collection makefile for:    bush
# Date created:				20 December 2004
# Whom:					Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=		bush
PORTVERSION=		1.0.3
PORTREVISION=	5
CATEGORIES=		shells
MASTER_SITES=		http://www.pegasoft.ca/downloads/	\
			http://66.11.182.223/downloads/
DISTNAME=		${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=		.tgz

MAINTAINER=		ports@FreeBSD.org
COMMENT=		The Business Shell

BUILD_DEPENDS=		gnatmake:${PORTSDIR}/lang/gnat	\
			bash:${PORTSDIR}/shells/bash

BROKEN=		does not build

USE_PGSQL=		yes

HAS_CONFIGURE=		yes
ADACFLAGS?=		${CFLAGS:N-fno-strict-aliasing}
USE_GMAKE=		yes
MAKE_ARGS=		GMAKE=${GMAKE} CPUTYPE=${CPUTYPE} PTHREAD_LIBS=${PTHREAD_LIBS}	\
			SDL_CONFIG=${SDL_CONFIG}
MAKE_ENV=		ADACFLAGS="${ADACFLAGS}"
MAKEFILE=		GNUmakefile
USE_SDL=		sdl image
USE_MYSQL=		yes
IGNORE_WITH_MYSQL=	323
REINPLACE_ARGS=		-i ""

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=			bush.1

PORTDOCS=		*

BASH2FIX=		examples/benchmark.bash examples/export.sh src/testsuite/test.sh

pre-build:
.for FILE in ${BASH2FIX}
	@${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|" ${WRKSRC}/${FILE}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/bush ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/bush.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.bush ${EXAMPLESDIR}
.endif

post-install:
	@${ECHO_CMD} ${PREFIX}/bin/bush >> /etc/shells
	@${ECHO_MSG} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/bush /etc/shells.bak ; \
	  ${ECHO_CMD} ${PREFIX}/bin/bush) > /etc/shells
	@${RM} /etc/shells.bak

.if defined(MAINTAINER_MODE)
test:	build
	@(cd ${BUILD_WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)
.endif

.include <bsd.port.mk>
