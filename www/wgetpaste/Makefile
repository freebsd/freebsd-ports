# Created by: Anonymous
# $FreeBSD$

PORTNAME=	wgetpaste
PORTVERSION=	2.30
CATEGORIES=	www
MASTER_SITES=	http://wgetpaste.zlin.dk/ \
		LOCAL/sunpoet
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} wgetpaste.example zlin.conf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Paste to several pastebin services via bash script

RUN_DEPENDS=	bash:shells/bash \
		wget:ftp/wget

USES=		tar:bzip2

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/etc/|${PREFIX}/etc/|g' \
		-e 's|\(INFO_COMMAND=\).*|\1"pkg info -aE"|' \
		-e 's|\(INFO_ARGS=\).*|\1|' \
			${WRKSRC}/wgetpaste

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/wgetpaste.d/ ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_SCRIPT} ${WRKSRC}/wgetpaste ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${DISTDIR}/wgetpaste.example ${STAGEDIR}${PREFIX}/etc/wgetpaste.conf.sample
	${INSTALL_DATA} ${DISTDIR}/zlin.conf ${STAGEDIR}${PREFIX}/etc/wgetpaste.d/
	${INSTALL_DATA} ${WRKSRC}/_wgetpaste ${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>
