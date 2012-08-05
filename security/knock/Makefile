# New ports collection makefile for:	knock
# Date Created:				2006-03-17
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	knock
PORTVERSION=	0.5
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	http://www.zeroflux.org/proj/knock/files/ \
		${MASTER_SITE_LOCAL:S,%SUBDIR%,sbz,}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	A flexible port-knocking server and client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	doorman-[0-9]*

GNU_CONFIGURE=	yes

CFLAGS+=	-I${LOCALBASE}/include

OPTIONS=	SERVER		"Install knockd server"		on \
		CLIENT		"Install knock client"		on

.include <bsd.port.pre.mk>

.if defined(WITH_SERVER)
MAN1=		knockd.1
USE_RC_SUBR=	knockd
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
			  -e "s#eth0#fxp0#g"		\
			  ${WRKSRC}/src/knockd.c

	@${REINPLACE_CMD} -e "s/#VERSION#/${PORTVERSION}/g" \
			  -e "s#eth0#fxp0#g"		\
			  ${WRKSRC}/doc/knock.1.in	\
			  ${WRKSRC}/doc/knockd.1.in	\
			  ${WRKSRC}/src/knockd.c	\
			  ${WRKSRC}/src/knock.c

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
