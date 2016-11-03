# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	openldap
PORTVERSION=	2.4.40
PORTREVISION=	1
CATEGORIES=	net linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	LDAP libraries (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	8.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	cyrus-sasl2 nspr nss
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}24-server/pkg-descr
PORTDOCS=	ANNOUNCEMENT CHANGES COPYRIGHT LICENSE README

# do not install any openldap configuration directories/files
post-patch:
	${RM} -rf ${WRKSRC}/etc

# use a native openldap configuration directories/files
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${LN} -sf ${LOCALBASE}/etc/openldap ${STAGEDIR}${PREFIX}/etc/openldap

.include <bsd.port.mk>
