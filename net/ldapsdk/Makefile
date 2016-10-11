# Created by: paul@FreeBSD.org
# $FreeBSD$

PORTNAME=	ldapsdk
PORTVERSION=	6.0.7
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	MOZILLA/directory/c-sdk/releases/v${PORTVERSION}/src
DISTNAME=	mozldap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mozilla LDAP sdk

LIB_DEPENDS=	libnspr4.so:devel/nspr

WRKSRC=		${WRKDIR}/${DISTNAME}/c-sdk

USES=		perl5 gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-optimize \
		--with-dist-prefix=${WRKDIR}/fakeroot \
		--with-nspr-inc=${LOCALBASE}/include/nspr \
		--with-nspr-lib=${LOCALBASE}/lib

post-extract:
	@${MKDIR} ${WRKDIR}/fakeroot

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/mozilla/directory
	@(cd ${WRKDIR}/fakeroot \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/mozilla/directory)

.include <bsd.port.mk>
