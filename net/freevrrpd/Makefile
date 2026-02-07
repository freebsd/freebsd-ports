PORTNAME=	freevrrpd
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	RFC 2338 compliant VRRP implementation

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	ocochard
GH_PROJECT=	FreeVRRPd

DISTVERSIONPREFIX=	v

MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

# XXX static PIE is not yet supported by the base system
MAKE_ENV+=	WITHOUT_PIE=true

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freevrrpd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/freevrrpd.conf.sample \
		${STAGEDIR}${PREFIX}/etc
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/freevrrpd \
		${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 \
		${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
