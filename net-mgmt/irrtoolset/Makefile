# New ports collection makefile for:	IRRToolSet
# Date created:				May 4th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	irrtoolset
PORTVERSION=	4.8.5
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_ISC} \
		ftp://ftp.ripe.net/tools/
MASTER_SITE_SUBDIR=IRRToolSet/${DISTNAME}
DISTNAME=	IRRToolSet-${PORTVERSION}

MAINTAINER=	oberman@es.net
COMMENT=	A suite of routing policy tools to interact with the IRR

PLIST_FILES=	bin/rpslcheck bin/peval bin/RtConfig

USE_BISON=	yes
USE_GMAKE=	yes
USE_GCC=	3.4
GNU_CONFIGURE=	Yes
CONFIGURE_ARGS=	--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include

MAN1=		RtConfig.1 peval.1 rpslcheck.1 IRR-Errors.1
MAN3=		librpsl.3

ALL_TARGET=	depend all

post-extract:
	@${RM} ${WRKSRC}/man/man1/CIDRAdvisor.1 ${WRKSRC}/man/man1/prpath.1
	@${RM} ${WRKSRC}/man/man1/prtraceroute.1 ${WRKSRC}/man/man1/?oe.1
	@${MV} ${WRKSRC}/man/man1/Errors.1 ${WRKSRC}/man/man1/IRR-Errors.1

post-patch:
	@${SED} -i.orig -e 's|#include <malloc.h>|/* #include <malloc.h> */|' \
	${WRKSRC}/src/irr/birdwhoisc.cc
	@${RM} ${WRKSRC}/man/man1/*.orig

.include <bsd.port.mk>
