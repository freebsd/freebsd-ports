# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	fontconfig
PORTVERSION=	2.10.95
PORTREVISION=	3
CATEGORIES=	x11-fonts linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	XML-based font configuration API for X Windows (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
RPMVERSION=	11.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	expat
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${RM} -r ${WRKSRC}/etc ${WRKSRC}/usr/share/fonts \
		${WRKSRC}/usr/share/fontconfig ${WRKSRC}/var

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${LN} -s ${LOCALBASE}/etc/fonts ${STAGEDIR}${PREFIX}/etc/
	${MKDIR} ${STAGEDIR}${PREFIX}/var/db/fontconfig

.include <bsd.port.mk>
