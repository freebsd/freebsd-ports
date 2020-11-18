# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	spread4
PORTVERSION=	4.2.0
CATEGORIES=	net perl5
MASTER_SITES=	LOCAL/ohauer
DISTNAME=	spread-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Spread Group Communication System, a network toolkit

GNU_CONFIGURE=	yes
USES=		gmake
USE_RC_SUBR=	spread
USE_LDCONFIG=	yes
ALL_TARGET=	all

USERS=		spread
GROUPS=		spread
RUNDIR=		/var/run/spread

PLIST_SUB+=	USERS=${USERS} GROUPS=${GROUPS} RUNDIR=${RUNDIR}
SUB_LIST+=	USERS=${USERS} GROUPS=${GROUPS}

WRKSRC=		${WRKDIR}/spread-src-${PORTVERSION}

PKGMESSAGE=	${WRKSRC}/license.txt
LICENSE_FILE=	${WRKSRC}/license.txt
OPTIONS_DEFINE=	DOCS
PORTDOCS=	DynamicConfiguration.txt Flush_or_SpreadAPI.txt \
		MultithreadedClients.txt Short_Buffer_Handling.txt \
		TODO PORTING

post-extract:
	@${REINPLACE_CMD} -e 's|INSTALLSUBDIRS=daemon docs|INSTALLSUBDIRS=daemon|' \
		${WRKSRC}/Makefile.in

post-install:
	(cd ${STAGEDIR}${PREFIX}/lib/ && ${STRIP_CMD} libspread.so.3.0.0 \
		libspread-core.so.3.0.0 libtspread-core.so.3.0.0)
	${INSTALL_DATA} ${WRKSRC}/docs/sample.spread.conf \
		${STAGEDIR}${PREFIX}/etc/spread.conf.sample
	${INSTALL_DATA} ${WRKSRC}/docs/sample.spread.access_ip \
		${STAGEDIR}${PREFIX}/etc/spread.access_ip.sample
	(cd ${WRKSRC} && ${INSTALL_DATA} docs/*.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	(cd ${WRKSRC} && ${INSTALL_DATA} docs/*.3 \
		${STAGEDIR}${MANPREFIX}/man/man3)
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${RUNDIR}
	(cd ${WRKSRC}/docs && \
		${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
