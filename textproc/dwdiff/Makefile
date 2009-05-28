# New ports collection makefile for:	dwdiff
# Date created:		30 September 2006
# Whom:			Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	dwdiff
PORTVERSION=	1.5.2
CATEGORIES=	textproc
MASTER_SITES=	http://os.ghalkes.nl/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A delimited word diff program

OPTIONS=	UNICODE	"Build with Unicode support"	on

MAKE_JOBS_SAFE=	yes

HAS_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"

MAN1=		${PORTNAME}.1
PORTDOCS=	COPYING Changelog README

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
MANLANG=	"" nl
LANGS=		de nl
.else
CONFIGURE_ARGS+=	--without-gettext
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_UNICODE)
LIB_DEPENDS+=	icudata:${PORTSDIR}/devel/icu
.else
CONFIGURE_ARGS+=	--without-unicode
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
.if !defined(WITHOUT_NLS)
.for lang in ${MANLANG:N""}
	@${MKDIR} ${MAN1PREFIX}/man/${lang}/man1
	${INSTALL_MAN} ${WRKSRC}/man/${lang}/${MAN1} ${MAN1PREFIX}/man/${lang}/man1
.endfor
.for lang in ${LANGS}
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
	    ${PREFIX}/share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.endif

.include <bsd.port.post.mk>
