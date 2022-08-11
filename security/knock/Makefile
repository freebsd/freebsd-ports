PORTNAME=	knock
PORTVERSION=	0.5
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	http://www.zeroflux.org/proj/knock/files/ \
		LOCAL/sbz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Flexible port-knocking server and client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	doorman

GNU_CONFIGURE=	yes

CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_MULTI=	MT1
OPTIONS_MULTI_MT1=	CLIENT SERVER
OPTIONS_DEFAULT=	CLIENT SERVER

CLIENT_DESC=	Install knock client
SERVER_DESC=	Install knockd server

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSERVER}
USE_RC_SUBR=	knockd
PLIST_FILES+=	bin/knockd \
		etc/knockd.conf.sample \
		man/man1/knockd.1.gz
.endif

.if ${PORT_OPTIONS:MCLIENT}
PLIST_FILES+=	bin/knock \
		man/man1/knock.1.gz
.endif

post-patch:
	@${REINPLACE_CMD} -e "s#%%PREFIX%%#${PREFIX}#g"	\
			  -e "s#eth0#fxp0#g"		\
			  ${WRKSRC}/src/knockd.c

	@${REINPLACE_CMD} -e "s/#VERSION#/${PORTVERSION}/g" \
			  -e "s#eth0#fxp0#g"		\
			  ${WRKSRC}/doc/knock.1.in	\
			  ${WRKSRC}/doc/knockd.1.in	\
			  ${WRKSRC}/src/knockd.c	\
			  ${WRKSRC}/src/knock.c

do-install:
.if ${PORT_OPTIONS:MSERVER}
	${INSTALL_PROGRAM} ${WRKSRC}/knockd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/knockd.conf ${STAGEDIR}${PREFIX}/etc/knockd.conf.sample
	${INSTALL_MAN} ${WRKSRC}/doc/knockd.1.in ${STAGEDIR}${MAN1PREFIX}/man/man1/knockd.1
.endif
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_PROGRAM} ${WRKSRC}/knock ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/knock.1.in ${STAGEDIR}${MAN1PREFIX}/man/man1/knock.1
.endif

.include <bsd.port.mk>
