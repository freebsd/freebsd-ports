# $FreeBSD$

PORTNAME=	surfraw
PORTVERSION=	2.2.8
CATEGORIES=	www
MASTER_SITES=	http://surfraw.alioth.debian.org/dist/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Command line interface to popular WWW search engines

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		perl5

post-patch:	.SILENT
	${REINPLACE_CMD} '\|xdg/surfraw|d' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|/bin/bash|${SH}|g' \
		-e 's/^function[[:space:]]//' \
		${WRKSRC}/examples/uzbl_load_url_from_surfraw.IN

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/examples/uzbl_load_url_from_surfraw \
		${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/surfraw-bash-completion \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/surfraw
.for f in surfraw.bookmarks surfraw.conf
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/etc/${f}.sample
	@if [ ! -f ${STAGEDIR}${PREFIX}/etc/${f} ]; then \
		${INSTALL_DATA} ${STAGEDIR}${PREFIX}/etc/${f}.sample \
			${STAGEDIR}${PREFIX}/etc/${f}; \
	fi
.endfor

.include "${.CURDIR}/manpages"
.include <bsd.port.mk>
