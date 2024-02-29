PORTNAME=	pfstat
PORTVERSION=	2.5
PORTREVISION=	8
CATEGORIES=	sysutils net
MASTER_SITES=	https://www.benzedrine.ch/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to render graphical statistics for pf
WWW=		https://www.benzedrine.ch/pfstat.html

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libgd.so:graphics/gd \
		libpng.so:graphics/png

USES=		iconv jpeg

USE_RC_SUBR=	pfstatd

MAKE_ARGS=	"LD_GD=gd"

PLIST_FILES=	bin/pfstat \
		bin/pfstatd \
		share/man/man8/pfstat.8.gz \
		share/man/man8/pfstatd.8.gz

post-patch:
	@${REINPLACE_CMD} -e 's|-lgd|-l$${LD_GD}|; s| -lttf||' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" \
		${WRKSRC}/pfstat.[c8]
	@${REINPLACE_CMD} 's|altq/|net/&|' ${WRKSRC}/pf.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfstat ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pfstatd/pfstatd ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pfstat.8 ${STAGEDIR}/${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/pfstatd/pfstatd.8 ${STAGEDIR}/${PREFIX}/share/man/man8

.include <bsd.port.mk>
