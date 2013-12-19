# $FreeBSD$

PORTNAME=	mohawk
PORTVERSION=	2.0.10
CATEGORIES=	www ipv6
MASTER_SITES=	http://fossil.etoilebsd.net/mohawk/tarball/ \
		http://fossil.bsdsx.fr/mohawk/tarball/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz?uuid=${PORTVERSION}

MAINTAINER=	mohawk@bsdsx.fr
COMMENT=	Simple and lightweight HTTP daemon

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libevent-2.0.so:${PORTSDIR}/devel/libevent2

PLIST_FILES+=	bin/mhtpasswd \
		man/man5/mohawk.conf.5.gz \
		man/man8/mhtpasswd.8.gz \
		man/man8/mohawk.8.gz \
		sbin/mohawk \
		etc/mohawk.conf.sample

PORTEXAMPLES=	*
USE_RC_SUBR=	mohawk

CFLAGS+=	-I${LOCALBASE}/include/event2/compat -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/event2

.include <bsd.port.options.mk>

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/minimal.conf ${STAGEDIR}${PREFIX}/etc/mohawk.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/mhtpasswd.sh ${STAGEDIR}${PREFIX}/bin/mhtpasswd
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.conf ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
