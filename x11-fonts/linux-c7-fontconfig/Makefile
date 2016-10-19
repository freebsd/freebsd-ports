# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	fontconfig
PORTVERSION=	2.10.95
CATEGORIES=	x11-fonts linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	XML-based font configuration API for X Windows (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
RPMVERSION=	7.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	expat
USE_LINUX_RPM=	yes

# We will use some other configuration file, so delete a linux one
# Don't let the linux fc-cache mess up the native cache file
post-patch:
	@${RM} -r ${WRKSRC}/etc ${WRKSRC}/usr/share/fonts \
		${WRKSRC}/usr/share/fontconfig ${WRKSRC}/var \
		${WRKSRC}/usr/bin/fc-cache \
		${WRKSRC}/usr/share/man/man1/fc-cache.1.gz

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${LN} -s ${LOCALBASE}/etc/fonts ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
