# $FreeBSD$

PORTNAME=	mohawk
PORTVERSION=	2.0.9
CATEGORIES=	www ipv6
MASTER_SITES=	http://fossil.etoilebsd.net/mohawk/tarball/ \
		http://fossil.bsdsx.fr/mohawk/tarball/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz?uuid=${PORTVERSION}

MAINTAINER=	mohawk@bsdsx.fr
COMMENT=	Simple and lightweight HTTP daemon

LICENSE=	BSD

LIB_DEPENDS=	event-2:${PORTSDIR}/devel/libevent2

PLIST_FILES+=	bin/mhtpasswd \
		sbin/mohawk \
		etc/mohawk.conf.sample

PORTEXAMPLES=	*
USE_RC_SUBR=	mohawk

MAN5=	mohawk.conf.5
MAN8=	mhtpasswd.8 \
	mohawk.8

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
