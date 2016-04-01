# Created by: Anonymous
# $FreeBSD$

PORTNAME=	wgetpaste
PORTVERSION=	2.27
CATEGORIES=	www
MASTER_SITES=	http://wgetpaste.zlin.dk/ \
		LOCAL/sunpoet
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}.example zlin.conf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Paste to several pastebin services via bash script

RUN_DEPENDS=	bash:shells/bash \
		wget:ftp/wget

NO_ARCH=	yes
NO_BUILD=	yes
USES=		tar:bzip2

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/etc/|${PREFIX}/etc/|g' \
		-e 's|\(INFO_COMMAND=\).*|\1"pkg_info -aE"|' \
		-e 's|\(INFO_ARGS=\).*|\1|' \
			${WRKSRC}/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.d/ ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}.example ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	${INSTALL_DATA} ${DISTDIR}/zlin.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.d/
	${INSTALL_DATA} ${WRKSRC}/_${PORTNAME} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>
