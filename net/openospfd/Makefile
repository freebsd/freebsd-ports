# $FreeBSD$

PORTNAME=	openospfd
PORTVERSION=	4.3
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	OPENBSD/OpenBGPD:openbsd \
		LOCAL/flz/openospfd/:freebsd
DISTFILES=	${DISTNAME}.tgz:openbsd \
		if_media.h:freebsd
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tgz

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Free implementation of the Open Shortest Path First Protocol

LICENSE=	ISCL

BROKEN=		requires old CARP implementation (interface layer)
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=	2017-01-15

CONFLICTS=	zebra-0* quagga-0*

LIB_DEPENDS=	libevent.so:devel/libevent2

MAKE_ENV=	BINDIR="${PREFIX}/sbin" \
		MANDIR="${PREFIX}/man/man"
COPTS=		-I${LOCALBASE}/include -DMD5_DIGEST_LENGTH=16
LDADD=		-L${LOCALBASE}/lib -levent -lmd
NO_WRKSUBDIR=	yes
USE_RC_SUBR=	${PORTNAME}
USERS=		_ospfd
GROUPS=		_ospfd

PLIST_FILES=	sbin/ospfctl \
		sbin/ospfd \
		man/man5/ospfd.conf.5.gz \
		man/man8/ospfctl.8.gz \
		man/man8/ospfd.8.gz

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/if_media.h ${WRKSRC}/ospfctl/

post-patch:
	@${REINPLACE_CMD} -e "s|<net/if_media\.h>|\"if_media.h\"|" \
		${WRKSRC}/ospfctl/ospfctl.c
	@${REINPLACE_CMD} -e "/rc.conf.local/d" ${WRKSRC}/ospfd/ospfd.conf.5
	@${REINPLACE_CMD} -e "s|SIMPLEQ|STAILQ|" ${WRKSRC}/ospfd/*.[chy]
	@${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|g" \
		${WRKSRC}/ospfd/ospfd.h \
		${WRKSRC}/ospfd/ospfd.8 \
		${WRKSRC}/ospfd/ospfd.conf.5
	@${REINPLACE_CMD} -e "s|__dead|__dead2|" \
		${WRKSRC}/ospfd/log.h \
		${WRKSRC}/ospfd/ospfd.c \
		${WRKSRC}/ospfctl/ospfctl.c

.include <bsd.port.options.mk>

do-build:
.for subdir in ospfd ospfctl
	${MAKE_CMD} -C ${WRKSRC}/${subdir} COPTS="${COPTS}" LDADD="${LDADD}"
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ospfctl/ospfctl ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ospfctl/ospfctl.8 \
		${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/ospfd/ospfd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ospfd/ospfd.conf.5 \
		${STAGEDIR}${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/ospfd/ospfd.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
