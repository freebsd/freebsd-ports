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

MAINTAINER=	dinoex@FreeBSD.org

LIB_DEPENDS=	ldap.1:${PORTSDIR}/net/openldap

USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE} --with-python=${PYTHON_CMD}
WRKSRC=		${WRKDIR}/${DISTNAME:S=-src==}

pre-configure:
	@${CP} ${FILESDIR}/Makefile.pre.in ${WRKSRC}/Misc/Makefile.python-1.4

.include <bsd.port.mk>
