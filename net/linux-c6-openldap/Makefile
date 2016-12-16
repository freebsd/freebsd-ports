# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	openldap
PORTVERSION=	2.4.40
PORTREVISION=	2
CATEGORIES=	net linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Lightweight Directory Access Protocol libraries (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-openldap-[0-9]*

USES=		linux:c6
USE_LINUX=	cyrus-sasl2 nss nspr
RPMVERSION=	12.el6
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes
DESCR=	${.CURDIR}/../openldap24-server/pkg-descr

PORTDOCS=	ANNOUNCEMENT CHANGES COPYRIGHT LICENSE README

# do not install any openldap configuration directories/files
post-extract:
	${RM} -rf ${WRKSRC}/etc

# use a native openldap configuration directories/files
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${LN} -sf ${LOCALBASE}/etc/openldap ${STAGEDIR}${PREFIX}/etc/openldap

.include <bsd.port.mk>
