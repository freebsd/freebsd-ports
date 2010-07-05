# New ports collection makefile for:	shellinabox
# Date created:		25 june 2010
# Whom:			Olivier Cochard-Labbe <olivier@cochard.me>
#
# $FreeBSD$
#

PORTNAME=	shellinabox
PORTVERSION=	2.10
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	Publish command line shell through AJAX interface

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	\
		--prefix=${PREFIX} \
		--infodir=${PREFIX}/${INFO_PATH} \
		--mandir=${MANPREFIX}/man

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_RC_SUBR=	shellinaboxd
USERS=	shellinabox
GROUPS=	shellinabox

MAN1=		shellinaboxd.1

PORTDOCS=	AUTHORS ChangeLog INSTALL README COPYING GPL-2 NEWS TODO

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

SUB_FILES=	pkg-deinstall

post-install:
	@${MKDIR} ${PREFIX}/etc/shellinabox
	@${CHMOD} 700 ${PREFIX}/etc/shellinabox
	@${CHOWN} ${USERS}:${GROUPS} ${PREFIX}/etc/shellinabox
	${INSTALL_MAN} ${WRKSRC}/shellinaboxd.1 ${PREFIX}/man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shellinaboxd ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
