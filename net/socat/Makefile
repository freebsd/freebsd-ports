# Ports collection makefile for:	socat
# Date created:				May 14, 2002
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	socat
PORTVERSION=	1.7.2.1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.dest-unreach.org/socat/download/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Multipurpose relay and more

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_RC_SUBR=	socat
USE_OPENSSL=	yes
MAKE_JOBS_SAFE=	yes

PORTSCOUT=	skipv:2.0.0-b2

MAN1=		socat.1
PLIST_FILES=	bin/filan bin/procan bin/socat sbin/socat_wrapper
PORTDOCS=	EXAMPLES README SECURITY FAQ

.if ${CC} == clang
CFLAGS+=	-Wno-unused-comparison
.endif

do-install:
.for f in filan procan socat
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${FILESDIR}/socat_wrapper ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
