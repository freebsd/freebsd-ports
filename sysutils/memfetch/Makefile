# New ports collection makefile for:    memfetch
# Date created:         		25 Nov 2004
# Whom:					Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	memfetch
PORTVERSION=	0.05b
CATEGORIES=	sysutils
MASTER_SITES=	http://lcamtuf.coredump.cx/soft/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	onatan@gmail.com
COMMENT=	Utility to dump process memory

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_PERL5_RUN=	yes

USE_GETOPT_LONG=yes
CFLAGS+=	${CPPFLAGS}
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mffind.pl ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
