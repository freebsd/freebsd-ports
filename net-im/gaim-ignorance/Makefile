# New ports collection makefile for:	gaim-ignorance
# Date created:		17 April 2005
# Whom:			kevinb
#
# $FreeBSD$
#

PORTNAME=	ignorance
PORTVERSION=	1.3.1.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://bard.sytes.net/ignorance/
PKGNAMEPREFIX=	gaim-

MAINTAINER=	kruptos@mlinux.org
COMMENT=	Adds filtering capabilities to gaim

BUILD_DEPENDS=	gaim:${PORTSDIR}/net/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net/gaim

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes

EXAMPLESDIR_REL=${EXAMPLESDIR:S,^${PREFIX}/,,}
PLIST_SUB=	EXAMPLESDIR_REL=${EXAMPLESDIR_REL}

SUB_FILES=	pkg-message

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

post-extract:
	@${REINPLACE_CMD} -e "s/ignorance.conf/ignorance.conf.sample/g" ${WRKSRC}/Makefile.in
	@${MV} ${WRKSRC}/ignorance.conf ${WRKSRC}/ignorance.conf.sample

post-patch:
	@${REINPLACE_CMD} -e 's|-g3||' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/ignorance ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}
	@if ${TEST} ! -f ${PREFIX}/etc/gaim/ignorance.conf; then \
		${CP} ${PREFIX}/etc/gaim/ignorance.conf.sample ${PREFIX}/etc/gaim/ignorance.conf; \
	fi

.include <bsd.port.mk>
