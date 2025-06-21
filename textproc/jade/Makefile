PORTNAME=	jade
PORTVERSION=	1.2.1
PORTREVISION=	11
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/jade/

PATCH_SITES=	https://old-releases.ubuntu.com/ubuntu/pool/main/j/jade/
PATCHFILES=	jade_1.2.1-47.1.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Object-oriented SGML/XML parser toolkit and DSSSL engine
WWW=		http://www.jclark.com/jade/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr

CONFLICTS=	sp-1.*

GNU_CONFIGURE=	yes
USES=		desthack gmake libtool
USE_CXXSTD=	gnu++98
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-default-catalog=${PREFIX}/share/sgml/catalog
MAKE_JOBS_UNSAFE=	yes

pre-install:
	@${FIND} ${WRKSRC} \( -name \*.orig -o -name \*~ \) \
		-exec ${RM} \{} \;

post-install:
.for i in jade nsgmls sgmlnorm spam spent sx
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/$i
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/include/sp
	${INSTALL_DATA} ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/include/sp
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/jade
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${STAGEDIR}${PREFIX}/share/doc/jade
	${MKDIR} ${STAGEDIR}${PREFIX}/share/sgml/jade
	${INSTALL_DATA} ${WRKSRC}/dsssl/* ${STAGEDIR}${PREFIX}/share/sgml/jade
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xml/jade
	${INSTALL_DATA} ${WRKSRC}/pubtext/xml* ${STAGEDIR}${PREFIX}/share/xml/jade

.include <bsd.port.mk>
