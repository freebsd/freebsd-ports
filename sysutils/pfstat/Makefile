PORTNAME=	pfstat
DISTVERSION=	2.5
PORTREVISION=	9
CATEGORIES=	sysutils net
MASTER_SITES=	https://www.benzedrine.ch/

MAINTAINER=	rootnode+freebsd@wollwage.com
COMMENT=	Utility to render graphical statistics for pf
WWW=		https://www.benzedrine.ch/pfstat.html

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libgd.so:graphics/gd \
		libpfctl.so:net/libpfctl \
		libpng.so:graphics/png

USES=		iconv jpeg localbase:ldflags
USE_RC_SUBR=	pfstatd

CFLAGS+=	-I/usr/include/net
LDFLAGS+=	-lpfctl

PLIST_FILES=	bin/pfstat \
		bin/pfstatd \
		share/man/man8/pfstat.8.gz \
		share/man/man8/pfstatd.8.gz

post-patch:
	@${REINPLACE_CMD} -e "s|/etc/|${PREFIX}/etc/|" \
		${WRKSRC}/pfstat.[c8]

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfstat \
		${WRKSRC}/pfstatd/pfstatd ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pfstat.8 \
		${WRKSRC}/pfstatd/pfstatd.8 ${STAGEDIR}/${PREFIX}/share/man/man8

.include <bsd.port.mk>
