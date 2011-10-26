# New ports collection makefile for:	shellinabox
# Date created:		25 june 2010
# Whom:			Olivier Cochard-Labbe <olivier@cochard.me>
#
# $FreeBSD$
#

PORTNAME=	shellinabox
PORTVERSION=	2.10
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	olivier@cochard.me
COMMENT=	Publish command line shell through AJAX interface

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS=	ENABLE_CORES	"Patch shellinaboxd to enable core dumps." off

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	\
		--prefix=${PREFIX} \
		--infodir=${PREFIX}/${INFO_PATH} \
		--mandir=${MANPREFIX}/man

USE_RC_SUBR=	shellinaboxd
USERS?=		shellinabox
GROUPS?=	shellinabox

MAN1=		shellinaboxd.1

PORTDOCS=	AUTHORS ChangeLog INSTALL README COPYING GPL-2 NEWS TODO

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

SUB_FILES=	pkg-deinstall
SUB_LIST=	USERS=${USERS} GROUPS=${GROUPS}

.include <bsd.port.options.mk>

post-patch:
.if defined(WITH_ENABLE_CORES)
	@${REINPLACE_CMD} \
		-e 's|prctl(PR_SET_DUMPABLE,|// &|' \
		-e 's|setrlimit(RLIMIT_CORE,|// &|' \
			${WRKSRC}/shellinabox/shellinaboxd.c
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shellinaboxd ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif
	${MKDIR} ${ETCDIR}/
	${CHMOD} 700 ${ETCDIR}/
	${CHOWN} ${USERS}:${GROUPS} ${ETCDIR}/
	${INSTALL_MAN} ${WRKSRC}/shellinaboxd.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
