# ex:ts=8
# Ports collection makefile for:	retawq
# Date created:			Dec 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	retawq
PORTVERSION=	0.0.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl:${PORTSDIR}/devel/gettext

CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
USE_GMAKE=	yes
MAKE_ENV=	LDFLAGS="${LDFLAGS}"
ALL_TARGET=	# empty

post-patch:
	@${PERL} -pi -e "s,-lpthread,${PTHREAD_LIBS},g ; \
		s,%%LOCALBASE%%,${LOCALBASE},g ; \
		s,%%PREFIX%%,${PREFIX},g ; \
		s,^CC,#CC,g ; s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/retawq ${PREFIX}/bin
.for lang in de fr
	${INSTALL_DATA} ${WRKSRC}/i18n/${lang}.mo ${PREFIX}/share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo
.endfor

.include <bsd.port.mk>
