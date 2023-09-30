PORTNAME=	rmilter
PORTVERSION=	1.10.0
CATEGORIES=	mail

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Milter that performs rspamd, clamav, and other checks
WWW=		https://github.com/vstakhov/rmilter

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpcre.so:devel/pcre

NOT_FOR_ARCHS=		mips
NOT_FOR_ARCHS_REASON=	fails to compile: error: Unsupported word size

USE_GITHUB=	yes
GH_ACCOUNT=	vstakhov

USES=		compiler:c11 cmake pkgconfig bison ssl gnome
USE_GNOME=	glib20

USERS=		_rmilter
GROUPS=		_rmilter

WITH_SENDMAIL_BASE=	yes

OPTIONS_DEFINE=		DKIM
OPTIONS_DEFAULT=	DKIM

DKIM_DESC=		DKIM signing support

DKIM_LIB_DEPENDS=	libopendkim.so:mail/opendkim
DKIM_CMAKE_OFF=	-DENABLE_DKIM=OFF

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=       -Wno-error=int-conversion
.endif

# Workaround to prevent bsd.milter.mk from breaking the build with the recent clang
WITHOUT_MILTER_LDFLAGS=	yes
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

post-patch:
	${SED} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/freebsd/rmilter > ${WRKDIR}/rmilter
	@${REINPLACE_CMD} -E 's|BLAKE2_ALIGN\( 64 \) typedef struct __blake2b_state|typedef struct BLAKE2_ALIGN\( 64 \) __blake2b_state|g; \
		s|BLAKE2_ALIGN\( 64 \) typedef struct __blake2s_state|typedef struct BLAKE2_ALIGN\( 64 \) __blake2s_state|g' \
		${WRKSRC}/compat/blake2.h

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rmilter ${STAGEDIR}${PREFIX}/etc/rc.d/
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/rmilter ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/rmilter.conf.sample ${STAGEDIR}${PREFIX}/etc/

	${INSTALL} -d ${STAGEDIR}/var/run/rmilter

.include <bsd.port.post.mk>
