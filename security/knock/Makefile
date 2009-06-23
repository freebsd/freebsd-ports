# New ports collection makefile for:	knock
# Date Created:				2006-03-17
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	knock
PORTVERSION=	0.5.20051124
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/

MAINTAINER=	sbrabez@gmail.com
COMMENT=	A flexible port-knocking server and client

GNU_CONFIGURE=	yes

CFLAGS+=	-I${LOCALBASE}/include

OPTIONS=	SERVER		"Install knockd server"		on \
		CLIENT		"Install knock client"		on

RUNDIR=		/var/run
SUB_LIST=	RUNDIR=${RUNDIR}

.include <bsd.port.pre.mk>

.if defined(WITH_SERVER)
MAN1=		knockd.1
USE_RC_SUBR=	knockd.sh
PLIST_FILES+=	bin/knockd
PLIST_FILES+=	etc/knockd.conf.sample
.endif

.if defined(WITH_CLIENT)
MAN1+=		knock.1
PLIST_FILES+=	bin/knock
.endif

pre-configure:
.if defined(WITHOUT_SERVER) && defined(WITHOUT_CLIENT)
IGNORE=		at least one component must be selected for installation
.endif

post-patch:
	@${REINPLACE_CMD} -e "s#%%PREFIX%%#${PREFIX}#g"	\
			  -e "s#%%RUNDIR%%#${RUNDIR}#g"	\
			  -e "s#eth0#fxp0#g"		\
			  ${WRKSRC}/src/knockd.c

	@${REINPLACE_CMD} -e "s/#VERSION#/${PORTVERSION}/g" \
			  -e "s#eth0#fxp0#g"		    \
			  ${WRKSRC}/doc/knock.1.in	    \
			  ${WRKSRC}/doc/knockd.1.in

do-install:
.if defined(WITH_SERVER)
	${INSTALL_PROGRAM} ${WRKSRC}/knockd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/knockd.conf ${PREFIX}/etc/knockd.conf.sample
.endif

.if defined(WITH_CLIENT)
	${INSTALL_PROGRAM} ${WRKSRC}/knock ${PREFIX}/bin
.endif

post-install-script:
.if defined(WITH_SERVER)
	${INSTALL_MAN} ${WRKSRC}/doc/knockd.1.in ${MAN1PREFIX}/man/man1/knockd.1
.endif

.if defined(WITH_CLIENT)
	${INSTALL_MAN} ${WRKSRC}/doc/knock.1.in ${MAN1PREFIX}/man/man1/knock.1
.endif

.include <bsd.port.post.mk>
