# New ports collection makefile for:   whois
# Date created:                02 Oct 2003
# Whom:                        Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	whois
PORTVERSION=	4.6.20
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	filippo@widestore.net
COMMENT=	Marco d'Itri whois client

MAN1=	whois.1

USE_ICONV=	yes
USE_PERL5_BUILD=	yes
USE_REINPLACE=	yes
USE_GETOPT_LONG=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_ENV=	LDFLAGS="${LDFLAGS}"
MAKE_ARGS=	OPTS=""

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
LDFLAGS+=	-lintl
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
NO_PO=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|prefix\=/usr/local|prefix\=${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|/usr/share|${PREFIX}/share|g" ${WRKSRC}/po/Makefile
	@if [ -n "${NO_PO}" ]; \
		then ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/have_nls-patch; \
	fi

post-install:
	@if [ ! -n "${NO_PO}" ]; \
		then cd ${WRKSRC}/po && ${MAKE} install; \
	fi

.include <bsd.port.mk>
