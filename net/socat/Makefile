# Created by: ijliao
# $FreeBSD$

PORTNAME=	socat
PORTVERSION=	1.7.2.2
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
PORTDOCS=	EXAMPLES README SECURITY FAQ

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

# we could be on HEAD where CC is in fact clang 3.3 but since we have no 
# __FreeBSD_version tag from when the 3.3 import happened we have to do some
# probing
#
.if(${OSVERSION} >= 1000000)
_CLANG!=	cc --version | ${HEAD} -1 | ${SED} -e 's/.*clang version \([0-9]\)\.\([0-9]\).*/\1\2/'
CFLAGS+=	-Wno-unused-comparison
.endif

.if ${CC} == clang
CFLAGS+=	-Wno-unused-comparison
.endif

do-install:
.for f in filan procan socat
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.if ${ARCH} == "arm"
BROKEN=		Does not configure on arm
.endif

.include <bsd.port.mk>
