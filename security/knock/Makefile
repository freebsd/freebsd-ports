# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

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

CONFLICTS=	doorman-[0-9]*

GNU_CONFIGURE=	yes

CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	CLIENT SERVER
OPTIONS_DEFAULT=	CLIENT SERVER

.include <bsd.port.options.mk>

CLIENT_DESC=	Install knock client
SERVER_DESC=	Install knockd server

.if ${PORT_OPTIONS:MSERVER}
MAN1=		knockd.1
USE_RC_SUBR=	knockd
PLIST_FILES+=	bin/knockd
PLIST_FILES+=	etc/knockd.conf.sample
.endif

.if ${PORT_OPTIONS:MCLIENT}
MAN1+=		knock.1
PLIST_FILES+=	bin/knock
.endif

pre-configure:
.if ${PORT_OPTIONS:MSERVER} && ${PORT_OPTIONS:MCLIENT}
IGNORE=		at least one component must be selected for installation
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
	${INSTALL_PROGRAM} ${WRKSRC}/knockd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/knockd.conf ${PREFIX}/etc/knockd.conf.sample
.endif

.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_PROGRAM} ${WRKSRC}/knock ${PREFIX}/bin
.endif

post-install-script:
.if ${PORT_OPTIONS:MSERVER}
	${INSTALL_MAN} ${WRKSRC}/doc/knockd.1.in ${MAN1PREFIX}/man/man1/knockd.1
.endif

.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_MAN} ${WRKSRC}/doc/knock.1.in ${MAN1PREFIX}/man/man1/knock.1
.endif

.include <bsd.port.mk>
