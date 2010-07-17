# New ports collection makefile for:	dwdiff
# Date created:		30 September 2006
# Whom:			Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	dwdiff
PORTVERSION=	1.8
CATEGORIES=	textproc
MASTER_SITES=	http://os.ghalkes.nl/dist/ \
		http://www.logvinov.ru/files/dist/ \
		LOCAL/avl
EXTRACT_SUFX=	.tgz

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A delimited word diff program

OPTIONS=	UNICODE	"Build with Unicode support"	on

MAKE_JOBS_SAFE=	yes

HAS_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"

MAN1=		${PORTNAME}.1 dwfilter.1
PORTDOCS=	COPYING Changelog README

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

.include <bsd.port.options.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
MANLANG=	"" nl nl.UTF-8
.else
CONFIGURE_ARGS+=	--without-gettext
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_UNICODE)
LIB_DEPENDS+=	icudata:${PORTSDIR}/devel/icu
.else
CONFIGURE_ARGS+=	--without-unicode
.endif

post-patch:
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|share/doc/${PORTNAME}-${PORTVERSION}|${DOCSDIR_REL}|' \
		${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e '/docdir/d' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
