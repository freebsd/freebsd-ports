# Created by: Max Laier <max@love2party.net>
# $FreeBSD$

PORTNAME=	pfstat
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.benzedrine.cx/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Utility to render graphical statistics for pf

LIB_DEPENDS=	libgd.so:graphics/gd

MAKE_ARGS=	"LD_GD=gd"
MAKE_ENV+=	__MAKE_CONF=/dev/null
USES=		iconv

USE_RC_SUBR=	pfstatd

PLIST_FILES=	bin/pfstat \
		bin/pfstatd \
		man/man8/pfstat.8.gz \
		man/man8/pfstatd.8.gz

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lgd|-l$${LD_GD}|; s| -lttf||' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" \
		${WRKSRC}/pfstat.[c8]
.if ${OSVERSION} >= 1100070
	@${REINPLACE_CMD} 's|altq/|net/&|' ${WRKSRC}/pf.c
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfstat ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pfstatd/pfstatd ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pfstat.8 ${STAGEDIR}/${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/pfstatd/pfstatd.8 ${STAGEDIR}/${PREFIX}/man/man8

.include <bsd.port.post.mk>
