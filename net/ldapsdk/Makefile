# New ports collection makefile for:	perldap
# Date created:	17 May 1999
# Whom:		paul@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	ldapsdk
PORTVERSION=	6.0.7
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	MOZILLA/directory/c-sdk/releases/v${PORTVERSION}/src
DISTNAME=	mozldap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mozilla LDAP sdk

LIB_DEPENDS=	nspr4.1:${PORTSDIR}/devel/nspr

WRKSRC=		${WRKDIR}/${DISTNAME}/c-sdk

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-optimize \
		--with-dist-prefix=${WRKDIR}/fakeroot \
		--with-nspr-inc=${LOCALBASE}/include/nspr \
		--with-nspr-lib=${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes

post-extract:
	@${MKDIR} ${WRKDIR}/fakeroot

do-install:
	@${MKDIR} ${PREFIX}/mozilla/directory
	@(cd ${WRKDIR}/fakeroot \
		&& ${COPYTREE_SHARE} . ${PREFIX}/mozilla/directory)

.include <bsd.port.mk>
