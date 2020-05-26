# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shellinabox
PORTVERSION=	2.20
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	www

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Publish command line shell through AJAX interface

LICENSE=	GPLv2

USES=	autoreconf libtool ssl

OPTIONS_DEFINE=	CORES NOLOGIN
CORES_DESC=	Patch shellinaboxd to enable core dumps
NOLOGIN_DESC=	Login through ssh (not through login)

GNU_CONFIGURE=	yes
USE_GITHUB=	yes

USE_RC_SUBR=	shellinaboxd
USERS?=		shellinabox
GROUPS?=	shellinabox

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

SUB_FILES=	pkg-deinstall
SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS}

CONFIGURE_ARGS=	--disable-runtime-loading --disable-pam \
		CFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

NOLOGIN_CONFIGURE_ON=	--disable-login

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
	@${MKDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
