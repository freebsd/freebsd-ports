# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	shellinabox
PORTVERSION=	2.14
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	olivier@cochard.me
COMMENT=	Publish command line shell through AJAX interface

LICENSE=	GPLv2

OPTIONS_DEFINE=	CORES NOLOGIN
CORES_DESC=	Patch shellinaboxd to enable core dumps
NOLOGIN_DESC=	Login through ssh (not through login)

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	\
		--prefix=${PREFIX} \
		--infodir=${PREFIX}/${INFO_PATH} \
		--mandir=${MANPREFIX}/man

USE_RC_SUBR=	shellinaboxd
USERS?=		shellinabox
GROUPS?=	shellinabox

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

SUB_FILES=	pkg-deinstall
SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS}

NOLOGIN_CONFIGURE_ON=	--disable-login

BROKEN_powerpc=	Does not load on powerpc

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MCORES}
	@${REINPLACE_CMD} \
		-e 's|prctl(PR_SET_DUMPABLE,|// &|' \
		-e 's|setrlimit(RLIMIT_CORE,|// &|' \
			${WRKSRC}/shellinabox/shellinaboxd.c
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shellinaboxd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/shellinaboxd.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
