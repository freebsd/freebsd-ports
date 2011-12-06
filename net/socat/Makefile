# Ports collection makefile for:	socat
# Date created:				May 14, 2002
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	socat
PORTVERSION=	1.7.2.0
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
PLIST_FILES=	bin/filan bin/procan bin/socat

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PORTDOCS=	EXAMPLES README SECURITY FAQ
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
