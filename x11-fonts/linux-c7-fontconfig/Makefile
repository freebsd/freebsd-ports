# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	fontconfig
PORTVERSION=	2.13.0
CATEGORIES=	x11-fonts linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	XML-based font configuration API for X Windows (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
RPMVERSION=	4.3.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	expat freetype
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch:
	@${RM} -r ${WRKSRC}/etc ${WRKSRC}/usr/lib/fontconfig \
		${WRKSRC}/usr/share/fontconfig

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${LN} -s ${LOCALBASE}/etc/fonts ${STAGEDIR}${PREFIX}/etc/
	${MKDIR} ${STAGEDIR}${PREFIX}/var/db/fontconfig

.include <bsd.port.mk>
