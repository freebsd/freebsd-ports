# Created by: Anonymous
# $FreeBSD$

PORTNAME=	wgetpaste
PORTVERSION=	2.22
CATEGORIES=	www
MASTER_SITES=	http://wgetpaste.zlin.dk/ \
		LOCAL/sunpoet
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}.example zlin.conf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Paste to several pastebin services via bash script

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

NO_BUILD=	yes
USE_BZIP2=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} \
		-e 's|/etc/|${PREFIX}/etc/|g' \
		-e 's|\(INFO_COMMAND=\).*|\1"pkg_info -aE"|' \
		-e 's|\(INFO_ARGS=\).*|\1|' \
			${WRKSRC}/${PORTNAME}

do-install:
	${MKDIR} ${PREFIX}/etc/${PORTNAME}.d/ ${PREFIX}/share/zsh/site-functions/
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}.example ${PREFIX}/etc/${PORTNAME}.conf.sample
	${INSTALL_DATA} ${DISTDIR}/zlin.conf ${PREFIX}/etc/${PORTNAME}.d/
	${INSTALL_DATA} ${WRKSRC}/_${PORTNAME} ${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>
