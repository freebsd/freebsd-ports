# New ports collection makefile for:	php4-cryptopp
# Date created:				28 Jan 2004
# Whom:					tmelzer
#
# $FreeBSD$
#

PORTNAME=	cryptopp
PORTVERSION=	0.0.15
CATEGORIES=	security
MASTER_SITES=	http://bugs.tutorbuddy.com/download.php/
PKGNAMEPREFIX=	php4-
DISTNAME=	${PORTNAME}-php-${PORTVERSION}

MAINTAINER=	tmelzer@tomesoft.de
COMMENT=	A crypto++ php wrapper

BUILD_DEPENDS+=	${LOCALBASE}/lib/libcryptopp.a:${PORTSDIR}/security/cryptopp

WRKSRC=		${WRKDIR}/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAME}

USE_PERL5=	yes
USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes

CONFIGURE_ARGS=	--with-cryptopp

.if !defined(NOPORTDOCS)
PORTDOCS=	README ${PORTNAME}.doc
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-march=pentium3 -O3 -g -pipe -fomit-frame-pointer|${CFLAGS}|' ${WRKSRC}/config.m4

post-build:
# convert sgml documentation to plain text
	@${PERL} -e '$$/=">";' -e 'while(<>){s/<.*>//;print;}' < ${WRKSRC}/docs/${PORTNAME}.sgml > ${WRKSRC}/${PORTNAME}.doc

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
