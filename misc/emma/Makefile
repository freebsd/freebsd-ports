# New ports collection makefile for:	emma
# Date created:				7 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	emma
PORTVERSION=	0.8.1
CATEGORIES=	misc gnome python
MASTER_SITES=	http://rainbow.mimuw.edu.pl/~la181249/emma/packages/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.1/-1/}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/DateTime/DateTime.py:${PORTSDIR}/lang/py-mx-base

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.1//}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
USE_PYTHON=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

pre-configure:
.for file in install-sh missing mkinstalldirs
	${LN} -sf ${LOCALBASE}/share/automake/${file} ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
