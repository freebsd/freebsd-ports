# New ports collection makefile for:	ldapmodule
# Date created:		05.Jul 2000
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	ldapmodule
PORTVERSION=	1.10alpha3
PORTREVISION=	4
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	python-ldap
DISTNAME=	python-ldap-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An LDAP module for python

BROKEN=		"Depends on net/openldap12 which is no more. Maybe net/py-ldap2 will do the trick?"

LIB_DEPENDS=	ldap.1:${PORTSDIR}/net/openldap12

USE_PYTHON=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE} --with-python=${PYTHON_CMD}
WRKSRC=		${WRKDIR}/${DISTNAME:S=-src==}

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e '15s,^.*$$,#include "config.h",g' \
		${WRKSRC}/Modules/LDAPObject.c

pre-configure:
.if ${PYTHON_REL} >= 230
	@${SED} -e 's,@DEFS@,,g' ${FILESDIR}/Makefile.pre.in > \
		${WRKSRC}/Misc/Makefile.python-1.4
.else
	@${CP} ${FILESDIR}/Makefile.pre.in ${WRKSRC}/Misc/Makefile.python-1.4
.endif

.include <bsd.port.post.mk>
