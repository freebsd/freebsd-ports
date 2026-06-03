PORTNAME=	slrn
DISTVERSIONPREFIX=	pre
DISTVERSION=	1.0.4-9
CATEGORIES=	news
MASTER_SITES=	http://www.jedsoft.org/snapshots/ \
		https://micha.freeshell.org/libcanlock/patches/:canlock
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		slrn-${DISTVERSION}_libcanlock3_patches${EXTRACT_SUFX}:canlock

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SLang-based newsreader
WWW=		https://slrn.info/

LICENSE=	GPLv2+

LIB_DEPENDS=	libslang.so:devel/libslang2

USES=		gmake iconv

GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=	${ICONV_CONFIGURE_ARG} \
			--disable-inews \
			--with-slrnpull

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	all

CONFLICTS_INSTALL=	ja-slrn

OPTIONS_DEFINE=		CANLOCK DEVIEW DOCS NLS SSL
OPTIONS_DEFAULT=	CANLOCK SSL
OPTIONS_SUB=		yes

CANLOCK_DESC=	Enable Cancel-Lock support via libcanlock
DEVIEW_DESC?=	UUdecode view support

CANLOCK_LIB_DEPENDS=	libcanlock.so:news/libcanlock
CANLOCK_CONFIGURE_ON=	--with-canlock=${LOCALBASE}
CANLOCK_CONFIGURE_OFF=	--without-canlock
CANLOCK_EXTRA_PATCHES=	${WRKDIR}/slrn-${DISTVERSION}_libcanlock3_patches/patch-changes.txt \
			${WRKDIR}/slrn-${DISTVERSION}_libcanlock3_patches/patch-doc_manual.txt \
			${WRKDIR}/slrn-${DISTVERSION}_libcanlock3_patches/patch-doc_slrn.rc \
			${WRKDIR}/slrn-${DISTVERSION}_libcanlock3_patches/patch-src_art.c \
			${WRKDIR}/slrn-${DISTVERSION}_libcanlock3_patches/patch-src_misc.c \
			${WRKDIR}/slrn-${DISTVERSION}_libcanlock3_patches/patch-src_misc.h \
			${WRKDIR}/slrn-${DISTVERSION}_libcanlock3_patches/patch-src_post.c \
			${WRKDIR}/slrn-${DISTVERSION}_libcanlock3_patches/patch-src_startup.c
DEVIEW_LIB_DEPENDS=	libuu.so:converters/uulib
DEVIEW_CONFIGURE_WITH=	uulib
DOCS_CONFIGURE_OFF=	--with-docdir=${WRKSRC}/dummy
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls
SSL_USES=		ssl
SSL_CONFIGURE_WITH=	ssl

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/lib/sendmail,/usr/sbin/sendmail,' \
		${WRKSRC}/src/slrnfeat.hin

.include <bsd.port.mk>
