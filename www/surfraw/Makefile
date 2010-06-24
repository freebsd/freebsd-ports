# New ports collection makefile for:   surfraw
# Date created:                2000-08-03
# Whom:                        Christian Weisgerber <naddy@mips.inka.de>
#
# $FreeBSD$

PORTNAME=	surfraw
PORTVERSION=	2.2.7
CATEGORIES=	www
MASTER_SITES=	http://surfraw.alioth.debian.org/dist/

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Command line interface to popular WWW search engines

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes

MAN1=	elvi.1sr \
	opensearch-discover.1 \
	opensearch-genquery.1 \
	surfraw-update-path.1 \
	surfraw.1

post-patch:	.SILENT
	${REINPLACE_CMD} '\|xdg/surfraw|d' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|/bin/bash|${SH}|g' \
		-e 's/^function[[:space:]]//' \
		${WRKSRC}/examples/uzbl_load_url_from_surfraw.IN

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/examples/uzbl_load_url_from_surfraw \
		${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/surfraw-bash-completion \
		${PREFIX}/etc/bash_completion.d/surfraw
.for f in surfraw.bookmarks surfraw.conf
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/etc/${f}.sample
	@if [ ! -f ${PREFIX}/etc/${f} ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/${f}.sample \
			${PREFIX}/etc/${f}; \
	fi
.endfor

.include "${.CURDIR}/manpages"
.include <bsd.port.mk>
