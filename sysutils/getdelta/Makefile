# Ports collection makefile for:	getdelta
# Date created:			15 December 2007
# Whom:				Anton Statutov <astatutov@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	getdelta
PORTVERSION=	0.7.8
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GENTOO} \
		http://132.207.4.160/distfiles/ \
		http://distfiles.gentoo.org/distfiles/ \
		http://linux01.gwdg.de/~nlissne/
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	astatutov@gmail.com
COMMENT=	Script for reducing bandwidth load while upgrading ports disfiles

RUN_DEPENDS=	deltup>=0.4.4:${PORTSDIR}/sysutils/deltup \
		wget:${PORTSDIR}/ftp/wget \
		bash:${PORTSDIR}/shells/bash

USE_BZIP2=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/getdelta.sh
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},; \
		s,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/getdelta.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/getdelta.sh ${PREFIX}/bin/getdelta.sh

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
