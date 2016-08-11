# Created by: jfieber
# $FreeBSD$

PORTNAME=	jade
PORTVERSION=	1.2.1
PORTREVISION=	10
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/jade/ \
		http://dist.bsdlab.org/

#PATCH_SITES=	http://ftp.debian.org/debian/pool/main/j/jade/
PATCH_SITES=	http://dist.bsdlab.org/
PATCHFILES=	jade_1.2.1-35.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Object-oriented SGML/XML parser toolkit and DSSSL engine

RUN_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr

CONFLICTS=	sp-1.*

GNU_CONFIGURE=	yes
USES=		desthack gmake libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-default-catalog=${PREFIX}/share/sgml/catalog
MAKE_JOBS_UNSAFE=	yes

post-extract:
	@${CHMOD} u+w ${WRKSRC}/configure

pre-install:
	@${FIND} ${WRKSRC} \( -name \*.orig -o -name \*~ \) \
		-exec ${RM} -f \{} \;

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

.include <bsd.port.pre.mk>

# Same problem with textproc/openjade.
CPPFLAGS:=	-O ${CFLAGS:N-O*:N-m*}

.include <bsd.port.post.mk>
