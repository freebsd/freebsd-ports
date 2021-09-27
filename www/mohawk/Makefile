PORTNAME=	mohawk
DISTVERSION=	2.0.21
CATEGORIES=	www
MASTER_SITES=	https://fossil.bsdsx.fr/mohawk/tarball/?r=${DISTVERSION}&name=/

MAINTAINER=	dsx+mohawk@bsdsx.fr
COMMENT=	Simple and lightweight HTTP daemon

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		localbase uidfix
USE_RC_SUBR=	mohawk

CFLAGS+=	-I${LOCALBASE}/include/event2/compat

PLIST_FILES=	bin/mhtpasswd \
		man/man5/mohawk.conf.5.gz \
		man/man8/mhtpasswd.8.gz \
		man/man8/mohawk.8.gz \
		sbin/mohawk \
		etc/mohawk.conf.sample

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/minimal.conf ${STAGEDIR}${PREFIX}/etc/mohawk.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/mhtpasswd.sh ${STAGEDIR}${PREFIX}/bin/mhtpasswd
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.conf ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
