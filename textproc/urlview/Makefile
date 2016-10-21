# Created by: Josh Gilliam <josh@quick.net>
# $FreeBSD$

PORTNAME=	urlview
PORTVERSION=	0.9.20131021
PORTREVISION=	1
CATEGORIES=	textproc www

MAINTAINER=	udvzsolt@gmail.com
COMMENT=	URL extractor/launcher

LICENSE=	GPLv2

USES=		ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	sigpipe
GH_TAGNAME=	45443109

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/urlview \
		etc/urlview.conf.sample \
		man/man1/urlview.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		-e 's/DEFAULT_COMMAND.*url_handler.sh/DEFAULT_COMMAND "firefox/' \
		${WRKSRC}/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/urlview ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/urlview.man ${STAGEDIR}${MAN1PREFIX}/man/man1/urlview.1
	${INSTALL_DATA} ${WRKSRC}/sample.urlview \
		${STAGEDIR}${PREFIX}/etc/urlview.conf.sample

.include <bsd.port.mk>
