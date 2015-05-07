# $FreeBSD$

PORTNAME=	pimd
PORTVERSION=	2.2.0
CATEGORIES=	net

MAINTAINER=	olivier@cochard.me
COMMENT=	Lightweight stand-alone PIM-SM v2 multicast routing daemon

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	troglobit

USES=		tar:bzip2
HAS_CONFIGURE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/pathnames.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pimd ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/pimd.conf \
		${STAGEDIR}${PREFIX}/etc/pimd.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/pimd.in \
		${STAGEDIR}${PREFIX}/etc/rc.d/pimd
	${INSTALL_MAN} ${WRKSRC}/pimd.8 ${STAGEDIR}${PREFIX}/man/man8/

.include <bsd.port.mk>
