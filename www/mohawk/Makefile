# New ports collection makefile for:	mohawk
# Date created:		2011-04-15
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mohawk
PORTVERSION=	2.0.1
CATEGORIES=	www ipv6
MASTER_SITES=	http://fossil.etoilebsd.net/mohawk/tarball/ \
		http://fossil.bsdsx.fr/mohawk/tarball/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}?uuid=${PORTVERSION}

MAINTAINER=	mohawk@bsdsx.fr
COMMENT=	Simple and lightweight HTTP daemon

LICENSE=	BSD

LIB_DEPENDS=    event-2.0:${PORTSDIR}/devel/libevent2

PLIST_FILES+=	bin/mhtpasswd \
		sbin/mohawk \
		etc/mohawk.conf.sample

PORTEXAMPLES=	*
USE_RC_SUBR=	mohawk

MANCOMPRESSED=	yes

MAN5=	mohawk.conf.5
MAN8=	mhtpasswd.8 \
	mohawk.8

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 800502
BROKEN=		does not build
.endif

CFLAGS+=        -I${LOCALBASE}/include/event2/compat -I${LOCALBASE}/include
LDFLAGS+=       -L${LOCALBASE}/lib/event2

post-install:
	@${INSTALL_DATA} ${WRKSRC}/examples/minimal.conf ${PREFIX}/etc/mohawk.conf.sample
	@${INSTALL_SCRIPT} ${WRKSRC}/mhtpasswd.sh ${PREFIX}/bin/mhtpasswd
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/*.conf ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
