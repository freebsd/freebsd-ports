# Ports collection makefile for:	socat
# Date created:				May 14, 2002
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	socat
PORTVERSION=	1.7.1.1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.dest-unreach.org/socat/download/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Multipurpose relay and more

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_RC_SUBR=	socat
MAKE_JOBS_SAFE=	yes

MAN1=		socat.1

PORTSCOUT=	skipv:2.0.0-b2

.if !defined(NOPORTDOCS)
PORTDOCS=	EXAMPLES README SECURITY FAQ
.endif

PLIST_FILES=	bin/filan bin/procan bin/socat

OPTIONS=	SSL "OpenSSL support" on

.include <bsd.port.pre.mk>

.if defined(WITH_SSL)
# we can't use USE_OPENSSL=yes after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
