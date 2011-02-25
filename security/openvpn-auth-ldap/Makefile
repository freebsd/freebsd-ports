# New ports collection makefile for:	openvpn-auth-ldap
# Date created:		06 June 2007
# Whom:			Nick Barkas <snb@threerings.net>
#
# $FreeBSD$

PORTNAME=	openvpn-auth-ldap
PORTVERSION=	2.0.3
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	auth-ldap-${PORTVERSION}

MAINTAINER=	snb@FreeBSD.org
COMMENT=	LDAP authentication plugin for OpenVPN

BUILD_DEPENDS=	re2c:${PORTSDIR}/devel/re2c \
		${NONEXISTENT}:${PORTSDIR}/security/openvpn:extract

GNU_CONFIGURE=	yes
USE_OPENLDAP=	yes
OPENVPN_WRKSRC=	`cd ${PORTSDIR}/security/openvpn; make -V WRKSRC`
CONFIGURE_ARGS+=	--with-openldap=${LOCALBASE} \
			--with-openvpn=${OPENVPN_WRKSRC}

PORTDOCS=	README
PORTEXAMPLES=	auth-ldap.conf
PLIST_FILES=	lib/openvpn-auth-ldap.so

.include <bsd.port.pre.mk>

.if (${OSVERSION} >= 900000 && ${OSVERSION} < 900012) || ${OSVERSION} < 800505
BUILD_DEPENDS+=	${LOCALBASE}/bin/xz:${PORTSDIR}/archivers/xz
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/auth-ldap.conf ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
