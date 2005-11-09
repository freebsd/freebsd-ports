# ex:ts=8
# Ports collection makefile for:	wsdlpull
# Date created:			Mar 18, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wsdlpull
PORTVERSION=	1.9.5.c
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ WSDL Parser

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
WRKSRC=		${WRKDIR}/${DISTNAME:R}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/wsdl
INSTALLS_SHLIB=	yes

DOCSDIR=	${PREFIX}/share/doc/wsdl
PORTDOCS=	*

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} \
		-e "s,[$$][(]prefix[)]/docs,${DOCSDIR},"

.include <bsd.port.pre.mk>

post-install:
.for dir in ${PREFIX}/include/wsdl ${PREFIX}/share/${PORTNAME}
	@${FIND} ${dir} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${dir} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor

.include <bsd.port.post.mk>
