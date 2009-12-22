# New ports collection makefile for:	lugtools
# Date created:		20 April 2007
# Whom:			kitsune
#
# $FreeBSD$
#

PORTNAME=	lugtools
PORTVERSION=	0.2.0
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

RUN_DEPENDS+=	ldapadd:${PORTSDIR}/net/openldap${WANT_OPENLDAP_VER}-client \
		${PREFIX}/bin/sh-include:${PORTSDIR}/shells/shell-include

USE_PERL5=	yes

PLIST_FILES=	bin/lgadd bin/lgrm bin/lpwo bin/luadd bin/lurm bin/lgmod \
		libexec/shell-include/bash/lugtools \
		libexec/shell-include/sh/lugtools

MAN1=		lgadd.1 lgmod.1 lgrm.1 lpwo.1 luadd.1 lurm.1

MAN5=		dotlugtools.5

WRKSRC=		${WRKDIR}/${DISTNAME}

#nothing to configure
do-configure:
	@${ECHO} -n

#nothing to build
do-build:
	@${ECHO} -n

do-install:
	@${EXEC} cd ${WRKSRC} ; ${WRKSRC}/install ${PREFIX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
