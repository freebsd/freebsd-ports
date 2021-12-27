# Created by: Ulrich Spoerlein <uspoerlein@gmail.com>

PORTNAME=	symon
PORTVERSION=	2.88
CATEGORIES=	sysutils
MASTER_SITES=	https://wpd.home.xs4all.nl/symon/philes/ \
		LOCAL/uqs

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	Performance and information monitoring tool

SUB_FILES=	pkg-message

USES=		groff perl5 shebangfix
SHEBANG_FILES=	client/getsymonitem.pl
USE_PERL5=	build
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	-D_WANT_SEMUN

USERS=		_symon
GROUPS=		_symon

# Synonym for WITHOUT_SYMUX
.if defined(WITHOUT_RRD)
WITHOUT_SYMUX=	yes
.endif

.if !defined(WITHOUT_SYMUX)
LIB_DEPENDS+=	librrd.so:databases/rrdtool
.endif

.if defined(WITHOUT_SYMUX) && defined(WITHOUT_SYMON)
IGNORE=	you have defined both WITHOUT_SYMUX or WITHOUT_RRD *and* WITHOUT_SYMON
.endif

SUBDIR=		lib
.if !defined(WITHOUT_SYMON)
SUBDIR+=	symon
PLIST_SUB+=	SYMON=""
USE_RC_SUBR+=	symon
.else
PLIST_SUB+=	SYMON="@comment "
.endif
.if !defined(WITHOUT_SYMUX)
SUBDIR+=	symux
PLIST_SUB+=	SYMUX=""
USE_RC_SUBR+=	symux
.else
PLIST_SUB+=	SYMUX="@comment "
.endif
SUBDIR+=	client

MAKE_ARGS+=	SUBDIR="${SUBDIR}" RRDDIR="${LOCALBASE}" LORDER=echo TSORT=cat \
		SYSCONFDIR="${PREFIX}/etc" PREFIX="${STAGEDIR}/${PREFIX}"

.include <bsd.port.pre.mk>

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-patch:
# We need to teach symon about mbstat changes/removal in r253351 and r253361.
	@${RM} ${WRKSRC}/platform/FreeBSD/sm_mbuf.c
.if ${OPSYS} == FreeBSD
	@${REINPLACE_CMD} 's|altq/|net/&|' ${WRKSRC}/platform/FreeBSD/sm_pfq.c
.endif

.include <bsd.port.post.mk>
