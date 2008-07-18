# New ports collection makefile for:   whois
# Date created:                02 Oct 2003
# Whom:                        Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	whois
PORTVERSION=	4.7.26
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	nivo+kw+ports.bfa274@is-root.com
COMMENT=	Marco d'Itri whois client

USE_GMAKE=		yes
USE_ICONV=		yes
USE_PERL5_BUILD=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_ENV=	LDFLAGS="${LDFLAGS}"
MAKE_ARGS=	OPTS=""

MAN1=	mwhois.1

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
		s|/usr/local|${LOCALBASE}|g ; \
		s|share/man/|man/|g ; \
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
