# New ports collection makefile for:   aria
# Date created:        30 March 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aria
PORTVERSION=	0.10.2.t3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://rabien.virtualave.net/linux/storage/sources/ \
		http://aria.rednoah.com/storage/sources/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.t/test/}

MAINTAINER=	nakai@FreeBSD.org

USE_BZIP2=	yes
USE_GTK=	yes
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g; \
		s|-lssl|-lcrypto -lssl|g; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${PERL} -pi -e 's|^CXXFLAGS.*|CXXFLAGS = \@CXXFLAGS\@|' \
		${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/README.euc ${PREFIX}/share/doc/${PORTNAME}/
.endif

.include <bsd.port.mk>
