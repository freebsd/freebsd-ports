# New ports collection makefile for:	jailadmin
# Date created:				02 Apr 2004
# Whom:					Kirk Strauser <kirk@strauser.com>
#
# $FreeBSD$
#

PORTNAME=	jailadmin
PORTVERSION=	1.8
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://subwiki.honeypot.net/pub/Freebsd/JailAdmin/
DISTNAME=	jailadmin-${PORTVERSION}

MAINTAINER=	kirk@strauser.com
COMMENT=	A system for managing a set of named jails

USE_PERL5=	yes

PORTDOCS=	INSTALL README

.include <bsd.port.pre.mk>

.if defined(WITH_SNMP)
.if exists(${LOCALBASE}/lib/libsnmp.so.4) || defined(WITH_SNMP4)
LIB_DEPENDS+=	snmp.4:${PORTSDIR}/net-mgmt/net-snmp4
.else
LIB_DEPENDS+=	netsnmp.9:${PORTSDIR}/net-mgmt/net-snmp
.endif
PLIST_SUB+=	SNMP=""
.else
INSTALL_TARGET=	installbase
PLIST_SUB+=	SNMP="@comment "
.endif

pre-everything::
	@${ECHO}
	@${ECHO} "You can build ${PKGNAME} with the following options:"
	@${ECHO} "WITH_SNMP     install the additional SNMP management components"
	@${ECHO}

pre-install:
	@${REINPLACE_CMD} -e "s#^SITEPERLDIR=.*#SITEPERLDIR= ${SITE_PERL}#" ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
