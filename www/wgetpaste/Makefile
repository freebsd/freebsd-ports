# New ports collection makefile for:	wgetpaste
# Date created:				2 Jul 2009
# Whom:					Anonymous
#
# $FreeBSD$
#

PORTNAME=	wgetpaste
PORTVERSION=	2.14
CATEGORIES=	www
MASTER_SITES=	http://wgetpaste.zlin.dk/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}.example zlin.conf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Paste to several pastebin services via bash script

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

USE_BZIP2=	yes
NO_BUILD=	yes

post-patch:	.SILENT
	${REINPLACE_CMD} \
		-e 's|/etc/|${PREFIX}/etc/|g' \
		-e 's|\(INFO_COMMAND=\).*|\1"pkg_info -aE"|' \
		-e 's|\(INFO_ARGS=\).*|\1|' \
		${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/_${PORTNAME} \
		${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}.example \
		${PREFIX}/etc/${PORTNAME}.conf.sample
	${MKDIR} ${PREFIX}/etc/${PORTNAME}.d
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/zlin.conf \
		${PREFIX}/etc/${PORTNAME}.d

.include <bsd.port.mk>
