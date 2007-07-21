# New ports collection makefile for:	lugtools
# Date created:		20 April 2007
# Whom:			kitsune
#
# $FreeBSD$
#

PORTNAME=	lugtools
PORTVERSION=	0.1.2
CATEGORIES=	sysutils net
MASTER_SITES=	http://vvelox.net/src/ldap/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Handles creation and removal of LDAP POSIX user and groups

WANT_OPENLDAP_VER?=	23
.if (${WANT_OPENLDAP_VER} != 21) && (${WANT_OPENLDAP_VER} != 22) && (${WANT_OPENLDAP_VER} != 23) && (${WANT_OPENLDAP_VER} != 24)
BROKEN=	Incompatible OpenLDAP version: ${WANT_OPENLDAP_VER}
.endif

RUN_DEPENDS+=	ldapadd:${PORTSDIR}/net/openldap${WANT_OPENLDAP_VER}-client

USE_PERL5=	yes

PLIST_FILES=	bin/lgadd bin/lgrm bin/lpwo bin/luadd bin/lurm bin/lgmod

MAN1=		lpwo.1 \
		luadd.1 \
		lurm.1 \
		lgadd.1 \
		lgrm.1 \
		lgmod.1

MAN5=		dotlugtools.5

WRKSRC=		${WRKDIR}/${PORTNAME}

#nothing to configure
do-configure:
	@${ECHO} -n

#nothing to build
do-build:
	@${ECHO} -n

do-install:
	@${EXEC} cd ${WRKDIR}/${PORTNAME}/ ; ${WRKDIR}/${PORTNAME}/install ${PREFIX}

.include <bsd.port.mk>
