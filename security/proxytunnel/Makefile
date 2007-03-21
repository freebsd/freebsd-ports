# New ports collection makefile for:		proxytunnel
# Date created:					Sun Nov 25 15:16:44 BRST 2001
# Whom:						Hammurabi Mendes <hmendes@brturbo.com>
#
# $FreeBSD$
#

PORTNAME=	proxytunnel
PORTVERSION=	1.7.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Connects stdin and stdout to an origin server through an HTTPS proxy

USE_GMAKE=	yes
USE_GETOPT_LONG=yes

CFLAGS+=	-DUSE_SSL -DHAVE_SETPROCTITLE -DSPT_TYPE=1

MAKE_ENV+=	CC="${CC}" LDFLAGS="${LDFLAGS}"

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/proxytunnel
PORTDOCS=	CHANGES CREDITS README

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
CFLAGS+=	-DHAVE_GETOPT_LONG
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/d' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
