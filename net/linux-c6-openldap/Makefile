# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	openldap
PORTVERSION=	2.4.23
CATEGORIES=	net linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Lightweight Directory Access Protocol libraries (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-openldap-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
#USE_LINUX_APPS=	openssl
RPMVERSION=	32.el6_4.1
USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes
DESCR=	${.CURDIR}/../openldap24-server/pkg-descr

PLIST_FILES=	lib/liblber-2.4.so.2 lib/liblber-2.4.so.2.5.6 lib/libldap-2.4.so.2 lib/libldap-2.4.so.2.5.6 lib/libldap_r-2.4.so.2 lib/libldap_r-2.4.so.2.5.6 lib/libldif-2.4.so.2 lib/libldif-2.4.so.2.5.6 etc/openldap usr/share/man/man5/ldap.conf.5.gz usr/share/man/man5/ldif.5.gz usr/libexec/openldap/create-certdb.sh
DOCSDIR=	usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	ANNOUNCEMENT CHANGES COPYRIGHT LICENSE README

# do not install any openldap configuration directories/files
post-extract:
	${RM} -rf ${WRKSRC}/etc

# use a native openldap configuration directories/files
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${LN} -sf ${LOCALBASE}/etc/openldap ${STAGEDIR}${PREFIX}/etc/openldap

.include <bsd.port.mk>
