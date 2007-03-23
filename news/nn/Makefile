# New ports collection makefile for:	nn
# Date created:		24 September 1994
# Whom:			adam
#
# $FreeBSD$
#

PORTNAME=	nn
PORTVERSION=	6.7.3
CATEGORIES=	news
MASTER_SITES=	http://www.sourcefiles.org/Internet/News/Usenet_Clients/  \
		http://www.wa.apana.org.au/~dean/sources/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Newsreader

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -Iconf" LDFLAGS="${LDFLAGS} -s"

MAN1=		nn.1 nncheck.1 nngoback.1 nngrab.1  nngrep.1 nnpost.1 \
		nntidy.1 nnview.1 nnacct.1m nnadmin.1m nnstats.1m nnusage.1m
MAN8=		nnmaster.8 nnspew.8

.include <bsd.port.pre.mk>

pre-patch:
	@${CP} ${WRKSRC}/config.h-dist ${WRKSRC}/config.h.unparsed

pre-build:
	@${CAT} ${WRKSRC}/config.h.unparsed | ${SED} -e "s#SUB_PREFIX#${PREFIX}#" \
	    | ${SED} -e "s#SUB_MANPREFIX#${MANPREFIX}#" > ${WRKSRC}/config.h

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${DISTNAME} POST-INSTALL

.include <bsd.port.post.mk>
