# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	shellinabox
PORTVERSION=	2.14
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	olivier@cochard.me
COMMENT=	Publish command line shell through AJAX interface

LICENSE=	GPLv2

OPTIONS_DEFINE=	CORES DOCS NOLOGIN
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

MAN1=	shellinaboxd.1

PORTDOCS=	AUTHORS ChangeLog INSTALL README COPYING GPL-2 NEWS TODO

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

SUB_FILES=	pkg-deinstall
SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOLOGIN}
CONFIGURE_ARGS+=--disable-login
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not load on powerpc
.endif

post-patch:
.if ${PORT_OPTIONS:MCORES}
	@${REINPLACE_CMD} \
		-e 's|prctl(PR_SET_DUMPABLE,|// &|' \
		-e 's|setrlimit(RLIMIT_CORE,|// &|' \
			${WRKSRC}/shellinabox/shellinaboxd.c
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shellinaboxd ${PREFIX}/bin/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
	${MKDIR} ${ETCDIR}/
	${CHMOD} 700 ${ETCDIR}/
	${CHOWN} ${USERS}:${GROUPS} ${ETCDIR}/
	${INSTALL_MAN} ${WRKSRC}/shellinaboxd.1 ${MANPREFIX}/man/man1/

.include <bsd.port.post.mk>
