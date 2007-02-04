# New ports collection makefile for:	IRRToolSet
# Date created:				May 4th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	irrtoolset
PORTVERSION=	4.8.4
PORTREVISION=	1
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
GNU_CONFIGURE=	Yes
CONFIGURE_ARGS=	--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include

MAN1=		RtConfig.1 peval.1 rpslcheck.1 IRR-Errors.1
MAN3=		librpsl.3

.include <bsd.port.pre.mk>

post-extract:
	@${RM} ${WRKSRC}/man/man1/CIDRAdvisor.1 ${WRKSRC}/man/man1/prpath.1
	@${RM} ${WRKSRC}/man/man1/prtraceroute.1 ${WRKSRC}/man/man1/?oe.1
	@${MV} ${WRKSRC}/man/man1/Errors.1 ${WRKSRC}/man/man1/IRR-Errors.1

post-patch:
	@${SED} -i.orig -e 's|#include <malloc.h>|/* #include <malloc.h> */|' \
	${WRKSRC}/src/irr/birdwhoisc.cc
	@${RM} ${WRKSRC}/man/man1/*.orig

ALL_TARGET=	depend all

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.include <bsd.port.post.mk>
