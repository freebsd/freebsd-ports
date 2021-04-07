PORTNAME=	modsecurity3-apache
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.9-beta1-19
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gf76aaae
CATEGORIES=	security www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Intrusion detection and prevention engine / Apache Wrapper

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmodsecurity.so:security/modsecurity3

USES=		apache:2.4+ autoreconf
USE_GCC=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	SpiderLabs
GH_PROJECT=	ModSecurity-apache

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	V3LIB=${LOCALBASE}/lib V3INCLUDE=${LOCALBASE}/include

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	${INSTALL_LIB} ${WRKSRC}/src/.libs/mod_security3.so \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
