PORTNAME=	wgetpaste
PORTVERSION=	2.33
CATEGORIES=	www
MASTER_SITES=	https://github.com/zlin/wgetpaste/releases/download/${PORTVERSION}/ \
		https://wgetpaste.zlin.dk/:misc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		wgetpaste.example:misc \
	       	zlin.conf:misc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Paste to several pastebin services via bash script
WWW=		http://wgetpaste.zlin.dk/ \
		https://github.com/zlin/wgetpaste

RUN_DEPENDS=	bash:shells/bash \
		wget:ftp/wget

USES=		tar:xz

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
