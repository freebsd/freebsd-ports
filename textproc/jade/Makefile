# New ports collection makefile for:	jade
# Date created:		June 19, 1997
# Whom:			jfieber
#
# $FreeBSD$
#

PORTNAME=	jade
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/jade/

PATCH_SITES=	http://ftp.debian.org/debian/pool/main/j/jade/
PATCHFILES=	jade_1.2.1-18.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	kuriyama@FreeBSD.org

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-default-catalog=${PREFIX}/share/sgml/catalog

post-extract:
	@${CHMOD} u+w ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
USE_REINPLACE=	yes
#	This is to deal with the broken assumption that Vector<T>::size_type, 
#	String<T>::size_type is size_t as mentioned in doc/ideas.htm.  At least
#	I believe this is what is preventing jade from linking on the Alpha.
post-patch:
	${REINPLACE_CMD} -e 's/<size_t>/<unsigned int>/g' `find ${WRKSRC} -type f`
.endif

pre-install:
	@find ${WRKSRC} \( -name \*.orig -o -name \*~ \) -exec ${RM} -f \{} \;

post-install:
.for i in jade nsgmls sgmlnorm spam spent sx
	strip ${PREFIX}/bin/$i
.endfor
	${MKDIR} ${PREFIX}/include/sp
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/sp
	${MKDIR} ${PREFIX}/share/doc/jade
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${PREFIX}/share/doc/jade
	${MKDIR} ${PREFIX}/share/sgml/jade
	${INSTALL_DATA} ${WRKSRC}/dsssl/* ${PREFIX}/share/sgml/jade
	@if [ ! -f ${PREFIX}/share/sgml/catalog ]; then \
		${ECHO_CMD} "CATALOG \"${PREFIX}/share/sgml/jade/catalog\"" > ${PREFIX}/share/sgml/catalog; \
	else \
		${SETENV} LANG=C ${PERL} -ni -e 'print if !m|${PREFIX}/share/sgml/jade/catalog|;print "CATALOG \"${PREFIX}/share/sgml/jade/catalog\"\n" if eof;' ${PREFIX}/share/sgml/catalog; \
	fi

.include <bsd.port.post.mk>
